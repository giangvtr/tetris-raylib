#include <raylib.h>
#include "grid.h"
#include "colors.h"

int main(){

	//Set a blank window
	InitWindow(310,610,"My Tetris");

	//Set speed of our game
	SetTargetFPS(60);

	Grid myGrid;
	myGrid.Initialize();
    myGrid.grid[0][0] = 1;
	myGrid.grid[5][6] = 6;
	myGrid.grid[5][4] = 5;
	myGrid.Print();

	while(WindowShouldClose()==false){
		BeginDrawing();
		ClearBackground(DARKBLUE);
		myGrid.Draw();
		EndDrawing();
	}

	CloseWindow();

}
