/************************************************************************
* Class: Row
*
* Purpose: This class will relate to array2d class and has a member called rows.
			It will return certain locations of the array and its members.
*
* Manager functions:
* 	Row(Array2D<T> & ray, int row);
	Row(const Array2D<T> &, const int row);
	T & operator [](int column);
	const T & operator [] (int column) const;
*
* Methods:
*	Array2D<T> & m_array2D;
	int m_row;
*		...
*************************************************************************/

#ifndef Row_H
#define Row_H
#include "Array2D.h"

template <typename T> class Array2D;


template <typename T>
class Row
{
public:
	Row(Array2D<T> & ray, int row); //two arg c'tor
	Row(const Array2D<T> &, const int row); // const two arg c'tor
	T & operator [](int column); //returns location of cell
	const T & operator [] (int column) const;// same thing but const value
private:
	Array2D<T> & m_array2D;
	int m_row;
};
/**********************************************************************
* Purpose: This function sets the values and is two arg c'tor
*
* Precondition:
*    the new values are passed in to set private data members
*
* Postcondition:
*      the private members are set to new values
*
************************************************************************/
template <typename T>
Row<T>::Row(Array2D<T> & ray, int row) : m_row(row), m_array2D(ray) //two arg c'tor
{
}
template <typename T>
Row<T>::Row(const Array2D<T> & ray, const int row) : m_array2D(const_cast<Array2D<T> &>(ray)), m_row(row) //two arg c'tor that is const
{
}
/**********************************************************************
* Purpose: This function is the operator bracket for the coordinates and will return the location
			of the array of the certain cell
*
* Precondition:
*     the column is passed in to find the location of the cell using the row member
*
* Postcondition:
*      returns the location of the cell
*
************************************************************************/

template <typename T>
T & Row<T>::operator[](int column)
{
	int index = (m_array2D.m_col) * m_row + column;
	return m_array2D.m_array[index];
}
template <typename T>
const T & Row<T>::operator [] (int column) const //this function does the same thing except its a const value and function returned
{
	int index = (m_array2D.m_col) * m_row + column;
	return m_array2D.m_array[index];
}
#endif