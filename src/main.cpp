#include <raylib.h>
#include "grid.h"

int main(){

	//Set a blank window
	InitWindow(300,600,"My Tetris");

	//Set speed of our game
	SetTargetFPS(60);


	while(WindowShouldClose()==false){
		BeginDrawing();
		ClearBackground(DARKBLUE);
		
		EndDrawing();
	}

	CloseWindow();
	Grid myGrid;
	myGrid.Initialize();
	myGrid.Print();
}