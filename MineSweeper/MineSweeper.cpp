/*************************************************************
*
* Lab/Assignment: Lab 1 – MineSweeper program
*
* Overview:
*	This program will let the user play the game known as MineSweeper.
*	It willask the user to enter the diffuculty, then ask them to enter coordinates,
*	then it will ask whether they want to reveal that location or flag the location.
*	If all bombs squares are gone through, then the user wins and the game is over.
*	If they hit a bomb then they will lose.
*
* Input:
*	The input will consist of the coordinates, the choice to flag or reveal the location
*	and the type of difficulty.
*
*
* Output:
*	The output of the program will be a grid of the game. It will look something
* like this: 
*	Welcome to MineSweeper
What Difficulty would you like?
1. Beginner
2. Intermediate
3. Expert
1

       0  1  2  3  4  5  6  7  8  9
Row: 0 ■  ■  ■  ■  ■  ■  ■  ■  ■  ■
Row: 1 ■  ■  ■  ■  ■  ■  ■  ■  ■  ■
Row: 2 ■  ■  ■  ■  ■  ■  ■  ■  ■  ■
Row: 3 ■  ■  ■  ■  ■  ■  ■  ■  ■  ■
Row: 4 ■  ■  ■  ■  ■  ■  ■  ■  ■  ■
Row: 5 ■  ■  ■  ■  ■  ■  ■  ■  ■  ■
Row: 6 ■  ■  ■  ■  ■  ■  ■  ■  ■  ■
Row: 7 ■  ■  ■  ■  ■  ■  ■  ■  ■  ■
Row: 8 ■  ■  ■  ■  ■  ■  ■  ■  ■  ■
Row: 9 ■  ■  ■  ■  ■  ■  ■  ■  ■  ■
Enter coordinate for Row:

*
************************************************************/

#include "MineSweeper.h"
#include <ctime>
void MineSweeper::menu()
{
	bool mineSet = true; //if mine is already set then decrement value of mines
	bool gameover = false; //determines if game is over
	cout << "Welcome to MineSweeper" << endl;

	int choice = 0;
	cout << "What Difficulty would you like? " << endl;
	do{
		cout << "1. Beginner" << "\n2. Intermediate" << "\n3. Expert" << endl; //choice to decide what diffuclty
		cin >> choice;
		switch (choice)
		{
		case 1: //if intermediate diffuclty
		{
			srand(time(NULL)); //set random values for mines
			m_board.setColumn(10); //sets the rows and columns of the grid
			m_board.setRows(10);
			m_board.setMines(10);//sets the ammount of mines in the game
			m_board.DisplayBoard();
			for (int i = 0; i < m_board.getMines(); i++) //set the right ammount of mines on board
			{
				mineSet = m_board.addMine();
				if (mineSet == false)
				{
					i--; //if already there then add one extra
				}
			}
		}
			break;
		case 2:
		{
			srand(time(NULL));
			m_board.setColumn(16); //sets the rows columns and mines
			m_board.setRows(16);
			m_board.setMines(40);
			m_board.DisplayBoard();
			for (int i = 0; i < m_board.getMines(); i++)
			{
				mineSet = m_board.addMine(); //sets mines
				if (mineSet == false)
				{
					i--;
				}
			}
		}
			break;
		case 3:
		{
			srand(time(NULL));
			m_board.setColumn(16);
			m_board.setRows(30);
			m_board.setMines(100);
			m_board.DisplayBoard();
			for (int i = 0; i < m_board.getMines(); i++)
			{
				mineSet = m_board.addMine();
				if (mineSet == false)
				{
					i--;
				}
			}
		}
			break;
		}
	} while (choice != 1 && choice != 2 && choice != 3); //if not one of the three options then keep going in it

	do
	{
		int x;
		int y;
		int option;
		do
		{
			cout << "Enter coordinate for Row: " << endl;
			cin >> x;
		} while (x > m_board.getRows()); //if not in range of rows then keep going
		do
		{
			cout << "Enter coordinate for Column: " << endl;
			cin >> y;
		} while (y > m_board.getColumn()); //if not in range of columns then keep going


		cout << "Would you like to: " << endl << "1. Reveal" << endl << "2. Flag" << endl; //determine what they want to do with the cell
		cin >> option;
		switch (option)
		{
		case 1:
		{
			gameover = m_board.reveal(x, y); //if reveal option then reveal that cell
			m_board.floodFill(x, y); //fill the board if the cell is empty
		}
			break;
		case 2:
		{
			m_board.setFlag(x, y);//set the cell to a flag
		}
			break;
		}
		m_board.DisplayBoard(); //display the board
		if (m_board.countMask() == m_board.getMines()) //if the ammount of cells left is found then user wins
		{
			cout << "You WIN!!!!!!" << endl;
			gameover = true;
		}
	} while (gameover == false);
	if (gameover != false) //else display game over
		cout << "Game Over" << endl;
}