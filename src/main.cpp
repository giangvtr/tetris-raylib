#include <raylib.h>
#include "grid.h"
#include "colors.h"
#include "blockChild.cpp"
#include <iostream>
#include <filesystem>

int main(){
    std::cout << "Running from: " << std::filesystem::current_path() << std::endl;
	//Set a blank window
	InitWindow(310,610,"My Tetris");

	//Set speed of our game
	SetTargetFPS(60);

	Grid myGrid;
	myGrid.Initialize();
	myGrid.Print();

    BeBlock block_be = BeBlock();
    ZBlock block_t = ZBlock();

	while(WindowShouldClose()==false){
		BeginDrawing();
		ClearBackground(DARKBLUE);
		myGrid.Draw();
        block_t.Draw();
		EndDrawing();
	}

	CloseWindow();

}
