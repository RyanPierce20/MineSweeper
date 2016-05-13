/*************************************************************
* Author:		Ryan Pierce
* Filename:		Lab1.cpp
* Date Created:	1/4/16
* Modifications:	Latest Modifictaion 1/17/16
**************************************************************/
#include "Cells.h"
/**********************************************************************
* Purpose: This function is the default c'tor and sets values to null
*
* Precondition:
*     nothing
*
* Postcondition:
*      private members are null
*
************************************************************************/

Cells::Cells() : m_state(0), m_value(0)
{}
/**********************************************************************
* Purpose: This function is the two arg c'tor and sets private members
*
* Precondition:
*     the two values are passed in to set private members
*
* Postcondition:
*      the private data members are set
*
************************************************************************/

Cells::Cells(int value, int state) : m_state(state), m_value(value)
{}
/**********************************************************************
* Purpose: This function is the copy c'tor and sets the values to the copy
*
* Precondition:
*     the copy cells is passed in to set new values
*
* Postcondition:
*      the values is set to the copy
*
************************************************************************/

Cells::Cells(const Cells & copy) : m_state(copy.m_state), m_value(copy.m_value)
{}
/**********************************************************************
* Purpose: This function is the destructor
*
* Precondition:
*    nothing
*
* Postcondition:
*      nothing
*
************************************************************************/

Cells::~Cells()
{}
/**********************************************************************
* Purpose: This function returns the value of the cell
*
* Precondition:
*     nothing
*
* Postcondition:
*      returns the value
*
************************************************************************/

int Cells::getValue() const
{
	return m_value;
}
/**********************************************************************
* Purpose: This function returns the state of the cell
*
* Precondition:
*     nothing
*
* Postcondition:
*      Returns the state of the cell
*
************************************************************************/

int Cells::getState() const
{
	return m_state;
}
/**********************************************************************
* Purpose: This function sets the value prvate data member
*
* Precondition:
*     the value is passed in to set the private data member
*
* Postcondition:
*      private data membe is set to new value
*
************************************************************************/

void Cells::setValue(int value)
{
	m_value = value;
}
/**********************************************************************
* Purpose: This function sets the state of the cell
*
* Precondition:
*     the value of state is passed in
*
* Postcondition:
*     sets the new value = to the private data member
*
************************************************************************/

void Cells::setState(int state)
{
	m_state = state;
}