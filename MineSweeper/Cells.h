/************************************************************************
* Class: Cells
*
* Purpose: This class has the type of state and value for the cells. It will determine is the 
			cell is a bomb, uncovered, covered, or has a flag
*
* Manager functions:
* 	Cells();
	Cells(int value, int state);
	Cells(const Cells & copy);
	~Cells();
	int getValue() const;
	int getState() const;
	void setValue(int value);
	void setState(int state);
*
* Methods:
*	int m_value; //bomb or number
	int m_state; //flag, uncovered, covered 
*		...
*************************************************************************/

#ifndef Cells_H
#define Cells_H
#include <iostream>
using std::cout;
using std::endl;
#include "Array2D.h"

class Cells
{
public:
	Cells();
	Cells(int value, int state);
	Cells(const Cells & copy);
	~Cells();
	int getValue() const;
	int getState() const;
	void setValue(int value);
	void setState(int state);

private:
	int m_value; //bomb or number
	int m_state; //flag, uncovered, covered 

};
#endif