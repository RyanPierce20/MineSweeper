/************************************************************************
* Class: MineSweeper
*
* Purpose: This class is basically the controller class that will have the actions
			to play the game minesweeper
*
* Manager functions:
* 		void menu();
*
* Methods:
*		Board m_board;
*		...
*************************************************************************/

#include <iostream>
using std::endl;
using std::cout;
using std::cin;
#include "Board.h"

class MineSweeper
{
public:
	void menu();

private:
	Board m_board;

};