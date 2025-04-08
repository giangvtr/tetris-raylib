# MY TETRIS GAME FROM RAYLIB
* This repository is built on the skeleton of raylib-quickstart ([Source](https://github.com/raylib-extras/raylib-quickstart)) 
* A simple cross platform template for setting up a project with the bleeding edge raylib code.
Works with C or C++.
* See [Raylib Cheatsheet](https://www.raylib.com/cheatsheet/cheatsheet.html)

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
* Vector ([See lesson](https://www.learncpp.com/cpp-tutorial/introduction-to-containers-and-arrays/))
* Good practice for external global constants ([See lesson](https://www.learncpp.com/cpp-tutorial/constant-variables-named-constants/))
* Map 