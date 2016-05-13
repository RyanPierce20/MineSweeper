/*************************************************************
* Author:		Ryan Pierce
* Filename:		Lab1.cpp
* Date Created:	1/4/16
* Modifications:	Latest Modifictaion 1/17/16
**************************************************************/
#include <iostream>
#include <Windows.h>
using std::cout;
using std::endl;
#include "MineSweeper.h"
#define _CRTDBG_MAP_ALLOC


int main()
{

	HANDLE hStdout = 0; //for the colors
	COORD cursor;

	cursor.X = 0; //where to have the coloring start
	cursor.Y = 0;

	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hStdout, cursor);
	SetConsoleTextAttribute(hStdout, BACKGROUND_INTENSITY); //sets background color

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //checks for memory leaks

	MineSweeper a; //instantiation for the controller class
	a.menu();
	
}