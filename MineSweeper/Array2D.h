/************************************************************************
* Class: Array2D
*
* Purpose: This class creates a dynamic two-dimensional array that uses the class Array to make a 2D array
*
* Manager functions:
* 	Array2D();
	Array2D(const Array2D & copy);
	Array2D(int row, int col);
	~Array2D();
	Array2D & operator = (const Array2D & rhs);
	Row<T> operator [] (int index);
	const Row<T> operator [] (int index) const;
	int getRow()const;
	void setRow(int rows);
	int getColumn()const;
	void setColumn(int columns);
	T & Select(int row, int column);
*
* Methods:
*	Array<T> m_array;
	int m_row;
	int m_col;
*		...
*************************************************************************/

#ifndef Array2D_H
#define Array2D_H
#include "Row.h"
#include "Array2D.h"
#include "Array.h"

template <typename T> class Row; //uses row class

template <typename T>
class Array2D
{
public:
	friend class Row < T >; //uses rows members
	Array2D(); //default c'tor
	Array2D(const Array2D & copy); // copy construcotr
	Array2D(int row, int col); //two arg c'tor
	~Array2D(); //destructor
	Array2D & operator = (const Array2D & rhs); //op equals 
	Row<T> operator [] (int index); //bracket operator
	const Row<T> operator [] (int index) const; //bracket operator by const
	int getRow()const; //returns rows
	void setRow(int rows); //sets row
	int getColumn()const; //returns columns
	void setColumn(int columns); //sets columns
	T & Select(int row, int column); //selects certain cell
private:
	Array<T> m_array;
	int m_row;
	int m_col;
};

/**********************************************************************
* Purpose: This function is the defualt c'tor and sets values to null
*
* Precondition:
*     nothing
*
* Postcondition:
*     private members are null
*
************************************************************************/

template <typename T>
Array2D<T>::Array2D() :m_row(NULL), m_col(NULL), m_array(NULL) //default c'tor
{}
/**********************************************************************
* Purpose: This function is the copy c'tor
*
* Precondition:
*     sets new array2d to the copy
*
* Postcondition:
*      the array is set to the copy
*
************************************************************************/

template <typename T>
Array2D<T>::Array2D(const Array2D<T> & copy) : m_array(copy.m_array), m_col(copy.m_col), m_row(copy.m_row) //copy c'tor
{}
/**********************************************************************
* Purpose: This function is the two arg c'tor
*
* Precondition:
*     the values are passed in
*
* Postcondition:
*      the private data members are set
*
************************************************************************/

template <typename T>
Array2D<T>::Array2D(int row, int col) : m_row(row), m_col(col) // two arg c'tor
{
	m_array.setLength(row*col);
}
template <typename T>
Array2D<T>::~Array2D() //default c'tor
{}
/**********************************************************************
* Purpose: This function is the operator = function that will set values to the new array
*
* Precondition:
*     the old array is passed in and will set the new one equal to it
*
* Postcondition:
*      the new array is set equal to the new one
*
************************************************************************/

template <typename T>
Array2D<T> & Array2D<T>::operator = (const Array2D<T> & rhs)
{
	if (this != &rhs)
	{
		m_row = rhs.m_row; //set the values
		m_col = rhs.m_col;
		m_array = rhs.m_array;
	}
	return *this; //return the this pointer
}
/**********************************************************************
* Purpose: This function returns the location of the array
*
* Precondition:
*     the index is passed in to get the location of the cell
*
* Postcondition:
*      Returns the location of the cell
*
************************************************************************/

template <typename T>
Row<T> Array2D<T>::operator [] (int index)
{
	return Row<T>(*this, index);
}
template <typename T>
const Row<T> Array2D<T>::operator [] (int index) const //same thing just as a const function
{
	return Row<T>(*this, index);
}

/**********************************************************************
* Purpose: This function returns the ammount of rows
*
* Precondition:
*    nothing
*
* Postcondition:
*      Returns the number of rows
*
************************************************************************/

template <typename T>
int Array2D<T>::getRow() const //returns const row
{
	return m_row;
}
template <typename T>
void Array2D<T>::setRow(int rows) //sets the row value
{
	//if (rows == m_row)
	//{

	//}
	//else if (rows > 0 && m_row < rows && m_row > rows)
	//{
	m_row = rows;
	m_array.setLength(m_row*m_col); //sets the new length of the cell
	//}
	//else{
	//	//throw Exception("Not a Valid Input for Rows");
	//}
}
/**********************************************************************
* Purpose: This function returns the ammount of columns
*
* Precondition:
*    nothing
*
* Postcondition:
*      Returns the number of columns
*
************************************************************************/
template <typename T>
int Array2D<T>::getColumn() const //return columns
{
	return m_col;
}
template <typename T>
void Array2D<T>::setColumn(int columns) //sets the column value
{
	//if (columns == m_col)
	//{

	//}
	//else if (columns > 0 && m_col < columns && m_col > columns)
	//{
		m_col = columns; //sets private data member
		m_array.setLength(m_row*m_col); //gets new length of array
	//}
	//else{
	//	//throw Exception("Not a Valid Input for Columns");
	//}
}
/**********************************************************************
* Purpose: This function gets the location of the cell in the 2D array
*
* Precondition:
*     the row and column are passed in to get the loaction of the cell
*
* Postcondition:
*      Returns the location of the array
*
************************************************************************/

template <typename T>
T & Array2D<T>::Select(int row, int column)
{
	int index = (row*m_col) + column; //easier to read to set to an int
	return m_array[index]; //returns location of cell
}
#endif