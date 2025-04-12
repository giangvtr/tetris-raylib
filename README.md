# MY TETRIS GAME FROM RAYLIB
* This is a simple implementation of the classic Tetris game using the [raylib](https://www.raylib.com/) library, written in C++. It is based on the [original Cpp-Tetris-Game-with-raylib repository](https://github.com/educ8s/Cpp-Tetris-Game-with-raylib/tree/main) with several enhancements.
* A simple cross platform template for setting up a project with the bleeding edge raylib code.
Works with C or C++.
* Raylib quick-start skeleton ([Source](https://github.com/raylib-extras/raylib-quickstart))
* See [Raylib Cheatsheet](https://www.raylib.com/cheatsheet/cheatsheet.html)

# Additional Features
- **Soft Falling:** Hold the down arrow key to make the blocks descend faster, giving you more control over the game.
- **Leaderboard:** The game now features a leaderboard that saves high scores in a `root/resources/score.txt` file.
- **Multiple Levels:** Choose different levels, each with unique speeds and point systems.

# Instructions for players
- Click on the button to navigate through the menus and start the game.
- To quit to the main menu, press **Q**.

# How to start building
## VSCode Users (all platforms)
*Note* You must have a compiler toolchain installed in addition to vscode.

* Download the quickstart
* Rename the folder to your game name
* Open the folder in VSCode
* Run the build task ( CTRL+SHIFT+B or F5 )
* You are good to go

## Linux Users
```bashrc
cd build
./premake5 gmake2
cd ..
make
```
* The you are good to go

## CLion users
*Note* You must build the program (using premake) before editing the "Run/Debug configuration"
* Type: Native Application
* Executable: Found in this directory `/home/giangvu/CPPprog/raylib-tetris/bin/Debug/[name-of-your-program]`

# Prerequisite for C++
* Object-Oriented Programmation: Classes ([See lesson](https://www.learncpp.com/cpp-tutorial/introduction-to-object-oriented-programming/)), Inheritance ([See lesson](https://www.learncpp.com/cpp-tutorial/introduction-to-inheritance/))
* Vector ([See lesson](https://www.learncpp.com/cpp-tutorial/introduction-to-containers-and-arrays/)) : push_back function : https://www.youtube.com/watch?v=RXzzE2wnnlo&t=91s
* Good practice for external global constants ([See lesson](https://www.learncpp.com/cpp-tutorial/constant-variables-named-constants/))
* Map 

# Doxygen
* How to set up (see this [Youtube video](https://www.youtube.com/watch?v=pnnKzkNTo4w&t=195s))
* 