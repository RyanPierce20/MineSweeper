/************************************************************************
* Class: Board
*
* Purpose: This class creates the game board and will display everything with the board
			and will add any mines to the map. It also has a search algorithim to display numbers
*
* Manager functions:
* 	Board();
	Board(int row, int column);
	Board(const Board & copy);
	~Board();
	int getRows() const;
	int getColumn() const;
	int getMines() const;
	void setMines(int mines);
	void setRows(int row);
	void setColumn(int column);
	void DisplayBoard();
	Board & operator = (const Board & rhs);
	bool addMine();
	bool reveal(int x, int y);
	void floodFill(int x, int y);
	void setFlag(int x, int y);
	int countMask();
*
* Methods:
*	Array2D<Cells> m_cells;
	int m_row;
	int m_column;
	int m_mines;

*		...
*************************************************************************/

#ifndef Board_H
#define Board_H

#include <iostream>
using std::endl;
using std::cout;
#include "Array2D.h"
#include "Cells.h"

class Board
{
public:
	Board();
	Board(int row, int column);
	Board(const Board & copy);
	~Board();
	int getRows() const;
	int getColumn() const;
	int getMines() const;
	void setMines(int mines);
	void setRows(int row);
	void setColumn(int column);
	void DisplayBoard();
	Board & operator = (const Board & rhs);
	bool addMine();
	bool reveal(int x, int y);
	void floodFill(int x, int y);
	void setFlag(int x, int y);
	int countMask();


private:
	Array2D<Cells> m_cells;
	int m_row;
	int m_column;
	int m_mines;

};
#endif