/*************************************************************
* Author:		Ryan Pierce
* Filename:		Lab1.cpp
* Date Created:	1/4/16
* Modifications:	Latest Modifictaion 1/17/16
**************************************************************/

#include "Board.h"
#include "Cells.h"
#include <Windows.h>

/**********************************************************************
* Purpose: This function is the default c'tor for its data members
*
* Precondition:
*     nothing
*
* Postcondition:
*      values are sent to null
*
************************************************************************/

Board::Board() : m_row(NULL), m_column(NULL) //defualt c'tor set values to null
{}
/**********************************************************************
* Purpose: This function is the two arg c'tor
*
* Precondition:
*     sets the private data members from new info
*
* Postcondition:
*      private members are set
*
************************************************************************/

Board::Board(int row, int column) : m_row(row), m_column(column) //two arg c'tor set the private data members
{}
/**********************************************************************
* Purpose: This function is the copy c'tor for the values
*
* Precondition:
*     the copy board is passed in
*
* Postcondition:
*      sets the new values
*
************************************************************************/

Board::Board(const Board & copy) : m_cells(copy.m_cells), m_row(copy.m_row), m_column(copy.m_column)//copy c;tor that copies values to other array
{}
/**********************************************************************
* Purpose: This function is the destructor
*
* Precondition:
*     nothing
*
* Postcondition:
*     nothing
*
************************************************************************/

Board::~Board() //destructor
{}
/**********************************************************************
* Purpose: This function returns the number of rows
*
* Precondition:
*     nothing
*
* Postcondition:
*      Returns the number of rows
*
************************************************************************/

int Board::getRows() const //returns the private data member of rows
{
	return m_row;
}
/**********************************************************************
* Purpose: This function returns the columns
*
* Precondition:
*     noting
*
* Postcondition:
*      returns the columns
*
************************************************************************/

int Board::getColumn() const //returns the private data members of column
{
	return m_column;
}
/**********************************************************************
* Purpose: This function returns the mines count
*
* Precondition:
*     nothing
*
* Postcondition:
*      returns number of mines
*
************************************************************************/

int Board::getMines() const //returns the mines of the array for minesweeper
{
	return m_mines;
}
/**********************************************************************
* Purpose: This function sets the ammount of mines
*
* Precondition:
*     mine value is passed in
*
* Postcondition:
*      the private member is set
*
************************************************************************/

void Board::setMines(int mines) //sets the number of mines for the game
{
	m_mines = mines;
}
/**********************************************************************
* Purpose: This function sets the ammount of rows
*
* Precondition:
*     new row is passed in 
*
* Postcondition:
*      private data member is set
*
************************************************************************/

void Board::setRows(int row) //sets the row number for the game
{
	m_cells.setRow(row); //sets the rows in array 2d
	m_row = row;
}
/**********************************************************************
* Purpose: This function sets the private member columns
*
* Precondition:
*     column is passed in to set to private member
*
* Postcondition:
*      the private data member is set
*
************************************************************************/

void Board::setColumn(int column) //sets the private data member for the game
{
	m_cells.setColumn(column); //sets the columns in array 2d
	m_column = column;
}
/**********************************************************************
* Purpose: This function will pass in the location of cell and set the state to a ?
*
* Precondition:
*     the location is passed in
*
* Postcondition:
*      the state is set for the cell
*
************************************************************************/

void Board::setFlag(int x, int y) //location of the area to set flag
{
	m_cells[x][y].setState(2); //sets the flag to say if its a bomb
}
/**********************************************************************
* Purpose: This function rwill display the board and color the icons.
			
*
* Precondition:
*     nothing, the board will display once the user makes a move
*
* Postcondition:
*      displays the entire board and the revealed locations and the flagged icons 
		and the numbers associated with the bombs
*
************************************************************************/

void Board::DisplayBoard()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //sets the color
	const int DEFAULT = 7; //default is the number to set the board back to the same
	int covered = 254; //ascii value for solid square
	int bomb = 42; //ascii value for *
	int uncovered = 248; //ascii value for 0
	int flag = 63; //ascii value for ?

	cout << endl<< "     ";
	for (int l = 0; l < m_column; l++) //displays numbers for column
	{
		if (l < 10)
			cout << "  " << l;
		else
			cout << " " << l;
	}
	cout << endl;
	for (int j = 0; j < m_row; j++) //displays the rows numbers
	{
		if (j < 10)
			cout << "Row: " << j << " ";
		else
			cout << "Row:" << j << " ";
		for (int x = 0; x < m_column; x++)
		{
			if (m_cells[j][x].getState() == 0) //if its covered then display covered
			{
				cout << (char)covered << "  ";
			}
			if (m_cells[j][x].getState() == 1) //if its not a bomb then go in
			{
				if (m_cells[j][x].getValue() == -1) //if its a bomb then go in and display
				{
					SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_INTENSITY); //set color to red
					cout << (char)bomb;
					SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY); // set background back
					cout << "  ";
				}
				else if (m_cells[j][x].getValue() > 0) //if it has a value then go in
				{
					if (m_cells[j][x].getValue() == 1) //if a one then make it this color
					{
						SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						cout << m_cells[j][x].getValue();
						SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY);
						cout << "  ";
					}
					if (m_cells[j][x].getValue() == 2) //if a 2 then make it this color
					{
						SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
						cout << m_cells[j][x].getValue();
						SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY);
						cout << "  ";
					}
					if (m_cells[j][x].getValue() == 3) //same thing
					{
						SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
						cout << m_cells[j][x].getValue();
						SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY);
						cout << "  ";
					}
					if (m_cells[j][x].getValue() == 4) //same thing
					{
						SetConsoleTextAttribute(handle,FOREGROUND_BLUE);
						cout << m_cells[j][x].getValue();
						SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY);
						cout << "  ";
					}
					if (m_cells[j][x].getValue() == 5) //same thing
					{
						SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
						cout << m_cells[j][x].getValue();
						SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY);
						cout << "  ";
					}
					if (m_cells[j][x].getValue() == 6)
					{
						SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN);
						cout << m_cells[j][x].getValue();
						SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY);
						cout << "  ";
					}
					if (m_cells[j][x].getValue() == 7)
					{
						SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
						cout << m_cells[j][x].getValue();
						SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY);
						cout << "  ";
					}
					if (m_cells[j][x].getValue() == 8)
					{
						SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_BLUE);
						cout << m_cells[j][x].getValue();
						SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY);
						cout << "  ";
					}
				}
				else if (m_cells[j][x].getValue() == 0) //if no value then output certain shape
					cout << (char)uncovered << "  ";
			}
			if (m_cells[j][x].getState() == 2) //if a flag then output a ?
			{
				SetConsoleTextAttribute(handle, FOREGROUND_RED);
				cout << (char)flag;
				SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY);
				cout << "  ";
			}
		}
		cout << endl;
	}
}
/**********************************************************************
* Purpose: This function will set the other board equal to another board
*
* Precondition:
*     the board is passed in to set the new board
*
* Postcondition:
*      returns the new inforamtion of the board
*
************************************************************************/

Board & Board::operator = (const Board & rhs)
{
	if (this != &rhs) //if its not the same
	{
		m_row = rhs.m_row;
		m_column = rhs.m_column;
		m_cells = rhs.m_cells;
	}
	return *this; //return new info
}
/**********************************************************************
* Purpose: This function will put mines in the map depending on the difficulty in random locations
*
* Precondition:
*     nothnig is passed in. 
*
* Postcondition:
*      returns a bool to see if the ammount of mines is the right ammount
*		will randomly set the bombs
*
************************************************************************/

bool Board::addMine()
{
	int x = rand() % m_row; //random number for the row size
	int y = rand() % m_column; //random number for the column size

	if (m_cells[x][y].getValue() != -1) //if not a bomb already then go in
	{
		m_cells[x][y].setValue(-1); //set this location to a bomb
		for (int dx = x - 1; dx <= x + 1; dx++) //go through size of map 
		{
			for (int dy = y - 1; dy <= y + 1; dy++)
			{
				if (dx >= 0 && dx < m_row && dy >= 0 && dy < m_column)
				{
					if (m_cells[dx][dy].getValue() != -1) //if this location isnt a bomb then go in
					{
						if (m_cells[dx][dy].getValue() < 1)
							m_cells[dx][dy].setValue(1); //if its next to a bomb set value to 1
						else
							m_cells[dx][dy].setValue(m_cells[dx][dy].getValue() + 1); //else just increment the value
					}
				}
			}
		}
		return true;
	}
	return false;
}
/**********************************************************************
* Purpose: This function will pass in the location of the cell, then will reveal the 
			location of the cell.
*
* Precondition:
*     the location of the grid is passed in
*
* Postcondition:
*      returns a bool to see if its a bomb or not
*
************************************************************************/

bool Board::reveal(int x, int y)
{
	m_cells[x][y].setState(1);
	if (m_cells[x][y].getValue() == -1) //if bomb, send true and end game
	{
		return true;
	}
	if (m_cells[x][y].getState() == 1) //if not then return false to keep playing
	{
		return false;
	}
}
/**********************************************************************
* Purpose: This function will reveal the rest of mines around the empty value mine
			and will display up to the right ammount of mines that have a value then will stop
			in that direction. Checks North, NorthWest, West, SouthWest, SOuth, SouthEast, and East of the mine.
*
* Precondition:
*     the location of the cell is passed in
*
* Postcondition:
*      returns nothing but sets the state of being uncovered.And finds all mines with value then stops
*
************************************************************************/

void Board::floodFill(int x, int y)
{
	if (m_cells[x][y].getValue() != -1 && m_cells[x][y].getValue() < 1) //if not a bomb and the value is less than one then go in
	{
		if (x - 1 < m_row && x-1 >= 0 && y >= 0 && y < m_column && m_cells[x - 1][y].getState() != 1) //if not out of bounds, and state isnt covered then go in
		{//north
			if (m_cells[x - 1][y].getValue() == 0) //if not a number then set to uncover
			{
				m_cells[x - 1][y].setState(1);
				floodFill(x - 1, y); //recursive function and sends new location to keep searching
			}
			else if (m_cells[x - 1][y].getValue() > 0) //if a value then send new location and uncover but stop calling function.
			{
				m_cells[x - 1][y].setState(1);
			}
		}
		if (x - 1 < m_row && x -1 >=0 && y +1 >= 0 && y + 1 < m_column && m_cells[x - 1][y + 1].getState() != 1) //checks location northeast
		{
			if (m_cells[x - 1][y + 1].getValue() == 0) //if no vlaue
			{
				m_cells[x - 1][y + 1].setState(1); //set to uncover
				floodFill(x - 1, y + 1); //keeps searching for next location
			}
			else if (m_cells[x - 1][y + 1].getValue() > 0)
			{
				m_cells[x - 1][y + 1].setState(1);
			}
		}
		if (x < m_row && x >= 0 && y + 1 >= 0 && y + 1 < m_column && m_cells[x][y + 1].getState() != 1)//east
		{
			if (m_cells[x][y + 1].getValue() == 0)
			{
				m_cells[x][y + 1].setState(1);
				floodFill(x, y + 1);
			}
			else if (m_cells[x][y + 1].getValue() > 0)
			{
				m_cells[x][y + 1].setState(1);
			}
		}
		if (x + 1 < m_row && x + 1 >= 0 && y + 1 >= 0 && y + 1 < m_column && m_cells[x + 1][y + 1].getState() == 0)//southeast
		{
			if (m_cells[x + 1][y + 1].getValue() == 0)
			{
				m_cells[x + 1][y + 1].setState(1);
				floodFill(x + 1, y + 1);
			}
			else if (m_cells[x + 1][y + 1].getValue() > 0)
			{
				m_cells[x + 1][y + 1].setState(1);
			}
		}
		if (x + 1 < m_row && x + 1 >= 0 && y >= 0 && y < m_column && m_cells[x + 1][y].getState() == 0)//south
		{
			if (m_cells[x + 1][y].getValue() == 0)
			{
				m_cells[x + 1][y].setState(1);
				floodFill(x + 1, y);
			}
			else if (m_cells[x + 1][y].getValue() > 0)
			{
				m_cells[x + 1][y].setState(1);
			}
		}
		if (x + 1 < m_row && x + 1 >= 0 && y - 1>= 0 && y - 1 < m_column && m_cells[x + 1][y - 1].getState() == 0)//southwest
		{
			if (m_cells[x +1][y - 1].getValue() == 0)
			{
				m_cells[x + 1][y - 1].setState(1);
				floodFill(x + 1, y - 1);
			}
			else if (m_cells[x + 1][y - 1].getValue() > 0)
			{
				m_cells[x + 1][y - 1].setState(1);
			}
		}
		if (x < m_row && x >= 0 && y - 1 >= 0 && y - 1 < m_column && m_cells[x][y - 1].getState() == 0)//west
		{
			if (m_cells[x][y - 1].getValue() == 0)
			{
				m_cells[x][y - 1].setState(1);
				floodFill(x, y - 1);
			}
			else if (m_cells[x][y - 1].getValue() > 0)
			{
				m_cells[x][y - 1].setState(1);
			}
		}
		if (x - 1 < m_row && x - 1 >= 0 && y - 1 >= 0 && y - 1 < m_column && m_cells[x - 1][y - 1].getState() == 0)//northwest
		{
			if (m_cells[x - 1][y - 1].getValue() == 0)
			{
				m_cells[x - 1][y - 1].setState(1);
				floodFill(x - 1, y - 1);
			}
			else if (m_cells[x - 1][y - 1].getValue() > 0)
			{
				m_cells[x - 1][y - 1].setState(1);
			}
		}//every if statement is the same except checks all 8 locations around the cell
	}
}
/**********************************************************************
* Purpose: This function will go through the map and find all bombs
			and if its covered then count those also.
			If the right ammount of bombs are found, then user wins.
*
* Precondition:
*     Lnothing is passed in
*
* Postcondition:
*      returns the count of mines and covered spots then checks if user won
*
************************************************************************/

int Board::countMask()
{
	int count = 0;
	for (int x = 0; x < m_row; x++)
		for (int y = 0; y < m_column; y++)
			if (m_cells[x][y].getValue() == -1 || m_cells[x][y].getState() == 0) //if its a bomb or if its covered then count 1
				count++;

	return count;
}