#include <raylib.h>
#include <iostream>
#include <filesystem>
#include "game.h"
#include "constants.h"
#include "leaderboard.h"

//Different windows for the game
enum GameScreen { MENU = 0, GAMEPLAY, LEADERBOARD, LEVEL_SELECT};

int main(){
    std::cout << "Running from: " << std::filesystem::current_path() << std::endl;
	//Set a blank window
	InitWindow(500,620,"My Tetris");

	//Set speed of our game
	SetTargetFPS(60);
    Texture2D background = LoadTexture("../../resources/img/background.jpg");
    Color screenColor = {4,15,45,255};
    Font font = LoadFontEx("../../resources/font/setbackt.ttf", 64, 0, 0);
    // Game state
    GameScreen currentScreen = MENU;
    Game myGame = Game();
    Leaderboard lb = Leaderboard();

    //In case player make it to Leader board
    bool waitingForNameInput = false;
	std::string nameInput = "";


    //Set default level
    myGame.SetLevel(Game::Level::LEVEL1);

	Grid myGrid;
	myGrid.Initialize();
	myGrid.Print();

    //Random seed
    std::srand(std::time(nullptr));

	while(WindowShouldClose()==false){
	    myGame.HandleInput();
        BeginDrawing();

        switch(currentScreen){
          case MENU: {
                // Menu title
                DrawTexture(background,0, 252, WHITE);
                ClearBackground(screenColor);

                DrawText("Welcome to Tetris", 52, 80, 45, RAYWHITE);

                // Start button
                Rectangle startBtn = { 200, 200, 110, 40 };
                DrawRectangleRounded(startBtn, 0.3, 6,LIGHTGRAY);
                //DrawRectangleRec(startBtn, LIGHTGRAY);
                DrawText("Start", 230, 210, 20, BLACK);

                // Leaderboard button
                Rectangle leaderboardBtn = { 200, 270, 110, 40 };
                DrawRectangleRounded(leaderboardBtn, 0.3, 6,LIGHTGRAY);
                //DrawRectangleRec(leaderboardBtn, LIGHTGRAY);
                DrawText("Leaderboard", 213, 282, 14, BLACK);

                    // Bouton Choose Level
                Rectangle levelBtn = { 200, 340, 110, 40 };
                DrawRectangleRounded(levelBtn, 0.3, 6, LIGHTGRAY);
                DrawText("Choose Level", 207, 352, 14, BLACK);

                // Input
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    Vector2 mousePos = GetMousePosition();
                    if (CheckCollisionPointRec(mousePos, startBtn)) {
                        currentScreen = GAMEPLAY;
                    } else if (CheckCollisionPointRec(mousePos, leaderboardBtn)) {
                        currentScreen = LEADERBOARD;
                    } else if (CheckCollisionPointRec(mousePos, levelBtn)) {
                        currentScreen = LEVEL_SELECT;
                    }
                }
                break;
          }

          case GAMEPLAY: {
            // Run your existing game loop
            ClearBackground(DARKBLUE);
            myGame.Draw();

            //Score zone
            DrawTextEx(font, "Score", {365,15},30,2,RAYWHITE);
            Rectangle scoreBoard = {320, 55,170,60};
            DrawRectangleRounded(scoreBoard, 0.3, 6, BEIGE);

            char scoreText[10];
        	sprintf(scoreText, "%d", myGame.score);
        	Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

        	DrawTextEx(font, scoreText, {320 + (170 - textSize.x) / 2, 65}, 38, 2, WHITE);

            //Next block zone
            DrawTextEx(font, "Next", {370,175},30,2,RAYWHITE);
            Rectangle nextBlockScreen = {320,215,170,180};
            DrawRectangleRounded(nextBlockScreen, 0.3, 6, BEIGE);

            myGame.Draw();
            myGame.HandleInput();
            myGame.HandleSoftDrop();

            if (myGame.EventTriggered(myGame.speed)){
               myGame.MoveBlockDown(false);
            }

            // Escape to menu
            if (IsKeyPressed(KEY_Q)) {
                currentScreen = MENU;
            }
            //If game over

            if (myGame.gameOver) {
    			if (!waitingForNameInput) {
        			lb.LoadLeaderboardFromFile("../../resources/score.txt");

        			// Check if score qualifies
        			if (lb.IsHighScore(myGame.score)) {
            			waitingForNameInput = true;
        			}
    			}

    			if (waitingForNameInput) {
        			DrawText("YOU MADE THE LEADERBOARD!", 20, 120, 20, YELLOW);
        			DrawText("Enter your name:", 20, 170, 20, RAYWHITE);
        			DrawRectangle(20, 200, 200, 30, LIGHTGRAY);
        			DrawText(nameInput.c_str(), 25, 205, 20, BLACK);

        			// Handle keyboard input
        			int key = GetCharPressed();
        			while (key > 0) {
            			if ((key >= 32) && (key <= 125) && nameInput.length() < 12) {
                			nameInput += static_cast<char>(key);
            			}
            			key = GetCharPressed();
        			}

        			// Backspace
        			if (IsKeyPressed(KEY_BACKSPACE) && !nameInput.empty()) {
            			nameInput.pop_back();
        			}

        			// Submit name with Enter
        			if (IsKeyPressed(KEY_ENTER) && !nameInput.empty()) {
    					lb.AddScore(nameInput, myGame.score);
    					lb.SaveLeaderboardToFile("../../resources/score.txt");

    					// Reset everything
    					nameInput.clear();
    					waitingForNameInput = false;

    					currentScreen = LEADERBOARD; // 👈 jump straight to leaderboard!
					}

    			} else {
        			DrawText("GAME OVER", 15, 150, 28, RAYWHITE);
        			DrawText("Press Q to QUIT", 40, 250, 28, RAYWHITE);
        			DrawText("Press R to REPLAY", 25, 350, 28, RAYWHITE);
    			}
			}
            break;
          }

          case LEADERBOARD: {
                ClearBackground(screenColor);
                DrawText("Leaderboard", 40, 100, 40, RAYWHITE);

                // Display top 10 leaderboard scores
                lb.LoadLeaderboardFromFile("../../resources/score.txt");
				lb.DrawLeaderboard(font, 60, 160, 30, RAYWHITE);


                DrawText("Press [Q] to return", 60, 450, 16, GRAY);

                // Return to menu if ESC is pressed
                if (IsKeyPressed(KEY_Q)) {
                    currentScreen = MENU;
                }
                break;
            }

          case LEVEL_SELECT: {
              ClearBackground(screenColor);

              // Titre
              DrawText("Choose your level", 110, 40, 30, WHITE);

              // Coordonnées de base pour positionner les boutons
              const float btnWidth = 220;
              const float btnHeight = 50;
              const float x = (GetScreenWidth() - btnWidth) / 2.0f;  // Centrage horizontal
              const float spacing = 20;
              const float startY = 120;

              // Liste des boutons
              Rectangle levelBtns[5];
              for (int i = 0; i < 5; i++) {
                  levelBtns[i] = { x, startY + i * (btnHeight + spacing), btnWidth, btnHeight };
              }

              const char* levelLabels[5] = { "Level 1", "Level 2", "Level 3", "Level 4", "Level 5" };

              // Dessin des boutons
              for (int i = 0; i < 5; i++) {
                  DrawRectangleRounded(levelBtns[i], 0.3, 6, LIGHTGRAY);
                  int textWidth = MeasureText(levelLabels[i], 22);
                  DrawText(levelLabels[i], x + (btnWidth - textWidth) / 2, levelBtns[i].y + 13, 22, BLACK);
              }

              // Gestion des clics
              if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                  Vector2 mouse = GetMousePosition();
                  for (int i = 0; i < 5; i++) {
                      if (CheckCollisionPointRec(mouse, levelBtns[i])) {
                          myGame.SetLevel(static_cast<Game::Level>(i));  // stocker le niveau choisi
                          //Reset the game
                          myGame.Reset();
                          myGrid.Initialize();  // Reinitialize the grid
                          myGrid.Print();  // Print or clear the grid as needed

                          currentScreen = GAMEPLAY;                     // passer au jeu
                      }
                  }
              }
              break;
          } //end case
        } // end switch
		EndDrawing();
	}
	CloseWindow();
}
