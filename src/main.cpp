#include <raylib.h>
#include "grid.h"
#include "colors.h"
#include "blockChild.cpp"

int main(){

	//Set a blank window
	InitWindow(310,610,"My Tetris");

	//Set speed of our game
	SetTargetFPS(60);

	Grid myGrid;
	myGrid.Initialize();
	myGrid.Print();

    LBlock block_l = LBlock();


	while(WindowShouldClose()==false){
		BeginDrawing();
		ClearBackground(DARKBLUE);
		myGrid.Draw();
        block_l.Draw();
		EndDrawing();
	}

	CloseWindow();

}
