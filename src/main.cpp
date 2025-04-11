#include <raylib.h>
#include <iostream>
#include <filesystem>
#include "game.h"
#include "constants.h"

double lastUpdateTime = 0;
bool EvenTriggered(double interval){
  double currentTime = GetTime();
  if(currentTime - lastUpdateTime > interval){
    lastUpdateTime = currentTime;
    return true;
  }
  return false;
}

//Different windows for the game
enum GameScreen { MENU = 0, GAMEPLAY, LEADERBOARD };

int main(){
    std::cout << "Running from: " << std::filesystem::current_path() << std::endl;
	//Set a blank window
	InitWindow(310,610,"My Tetris");

	//Set speed of our game
	SetTargetFPS(60);
    Texture2D background = LoadTexture("../../resources/img/background.jpg");
    Color screenColor = {4,15,45,255};
    // Game state
    GameScreen currentScreen = MENU;
    Game myGame = Game();

	Grid myGrid;
	myGrid.Initialize();
	myGrid.Print();

	while(WindowShouldClose()==false){
	    myGame.HandleInput();
        BeginDrawing();

        switch(currentScreen){
          case MENU: {
                // Menu title
                DrawTexture(background,0, 252, WHITE);
                ClearBackground(screenColor);

                DrawText("Welcome to Tetris", 75, 80, 20, RAYWHITE);

                // Start button
                Rectangle startBtn = { 100, 200, 110, 40 };
                DrawRectangleRec(startBtn, LIGHTGRAY);
                DrawText("Start", 130, 210, 20, BLACK);

                // Leaderboard button
                Rectangle leaderboardBtn = { 100, 270, 110, 40 };
                DrawRectangleRec(leaderboardBtn, LIGHTGRAY);
                DrawText("Leaderboard", 113, 282, 14, BLACK);

                // Input
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    Vector2 mousePos = GetMousePosition();
                    if (CheckCollisionPointRec(mousePos, startBtn)) {
                        currentScreen = GAMEPLAY;
                    } else if (CheckCollisionPointRec(mousePos, leaderboardBtn)) {
                        currentScreen = LEADERBOARD;
                    }
                }
                break;
          }

          case GAMEPLAY: {
            // Run your existing game loop
            ClearBackground(DARKBLUE);
            myGame.Draw();
            myGame.HandleInput();
            if (EvenTriggered(constants::INTERVAL)){
               myGame.MoveBlockDown();
            }
            // Escape to menu
            if (IsKeyPressed(KEY_Q)) {
                currentScreen = MENU;
            }
            //If game over

            if(myGame.gameOver){
              DrawText("GAME OVER, BITCH !", 15, 150, 28, RAYWHITE);

            }
            break;
          }

            case LEADERBOARD: {
                DrawText("Leaderboard - Coming Soon", 40, 200, 18, RAYWHITE);
                DrawText("Press [ESC] to return", 60, 250, 16, GRAY);

                if (IsKeyPressed(KEY_Q)) {
                    currentScreen = MENU;
                }
                break;
            }
        }


		EndDrawing();
	}

	CloseWindow();

}
