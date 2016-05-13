/************************************************************************
* Class: Array
*
* Purpose: This class creates a dynamic one-dimensional array that can be * started at any base.
*
* Manager functions:
* 	Array();
	Array(int length, int start_index = 0);
	Array(const Array & copy);
	~Array();
	Array & operator = (const Array & rhs);
	T & operator [] (int index);
	int getStartIndex() const;
	void setStartIndex(int start_index);
	int getLength() const;
	void setLength(int length);
*
* Methods:
*	T * m_array;
	int m_length;
	int m_start_index;
*		...
*************************************************************************/

#ifndef Array_H
#define Array_H


template <typename T> //template
class Array
{
public:
	Array(); //default c'tor
	Array(int length, int start_index = 0); //two arg c'tor
	Array(const Array & copy); //copy constrictor
	~Array(); //destructor
	Array & operator = (const Array & rhs); //op equals c'tor
	T & operator [] (int index); //bracket op
	int getStartIndex() const;
	void setStartIndex(int start_index);
	int getLength() const;
	void setLength(int length);
private:
	T * m_array;
	int m_length;
	int m_start_index;
};
/**********************************************************************
* Purpose: This function is the defualt c'tor
*
* Precondition:
*     nothing 
*
* Postcondition:
*      the m_array, start index, and length are all created
*
************************************************************************/

template <typename T>
Array<T>::Array() : m_array(new T[0]), m_start_index(0), m_length(0)
{}
/**********************************************************************
* Purpose: This function sets the values to the private values
*
* Precondition:
*     length and start index are passed in to set to private members
*
* Postcondition:
*      the values are set to the private members
*
************************************************************************/

template <typename T>
Array<T>::Array(int length, int start_index = 0) :m_array(new T[length]), m_length(length), m_start_index(start_index)
{}
/**********************************************************************
* Purpose: This function passes in another Array type and copies it to the other array type
*
* Precondition:
*     the array to be copied over to is passed in
*
* Postcondition:
*      sets the newer array type to the older type
*
************************************************************************/

template <typename T>
Array<T>::Array(const Array<T> & copy) : m_array(new T[copy.m_length]), m_start_index(copy.m_start_index), m_length(copy.m_length)
{
	for (int i = 0; i < m_length; ++i) //deep copy
		m_array[i] = copy.m_array[i];
}
/**********************************************************************
* Purpose: This function deletes the m_array and is destructor
*
* Precondition:
*     nothing
*
* Postcondition:
*      the memory is deleted
*
************************************************************************/

template <typename T>
Array<T>::~Array()
{
	delete[]m_array; 
}
/**********************************************************************
* Purpose: This function is th operator equals function that will set two array types to each other equal
*
* Precondition:
*     the array type is passed in to set equal to other array
*
* Postcondition:
*      returns a this pointer to the newer array
*
************************************************************************/

template <typename T>
Array<T> & Array<T>::operator = (const Array<T> & rhs)
{
	if (this != &rhs) //if not this pointer
	{
		m_start_index = rhs.m_start_index; //set start index
		m_length = rhs.m_length; //set length

		delete[]m_array; //delete old array
		m_array = new T[rhs.m_length]; //make new array

		for (int i = 0; i < m_length; ++i) //deep copy the new array
			m_array[i] = rhs.m_array[i];
	}
	return *this;
}
/**********************************************************************
* Purpose: This function will return the array and its index location
*
* Precondition:
*     the index value is passed in to find the new location of the array
*
* Postcondition:
*      Returns the loctaion of he array
*
************************************************************************/

template <typename T>
T & Array<T>::operator [] (int index)
{
	if (index < m_start_index)
	{ }
		//throw Exception("You went Below the bounds!! Byeeeeee");
	//else if (index >= (m_length + m_start_index))
		//throw Exception("You Went Above the Bounds!!! See Ya!!");
	else
		return m_array[index - m_start_index];
}
/**********************************************************************
* Purpose: This function returns the start index of the array
*
* Precondition:
*     nothing
*
* Postcondition:
*      Returns the start index
*
************************************************************************/

template <typename T>
int Array<T>::getStartIndex() const
{
	return m_start_index;
}
/**********************************************************************
* Purpose: This function sets the start index to its private data member
*
* Precondition:
*     the new start index value is passed in
*
* Postcondition:
*      it sets the start index to its new value
*
************************************************************************/

template <typename T>
void Array<T>::setStartIndex(int start_index)
{
	m_start_index = start_index;
}
/**********************************************************************
* Purpose: This function returns the length of the array
*
* Precondition:
*     nothing
*
* Postcondition:
*      returns the value of the length of the array
*
************************************************************************/

template <typename T>
int Array<T>::getLength() const
{
	return m_length;
}
/**********************************************************************
* Purpose: This function sets the length of the array and will delete the old array
*
* Precondition:
*    the value of the length will be passed in to make a new length and array
*
* Postcondition:
*      nothing is returned but the length will be set
*
************************************************************************/

template <typename T>
void Array<T>::setLength(int length)
{
	if (length < 0) //if negative 
	{ }
		//throw Exception("NegativeLengthException");
	T * newData = new T[length]; //make new data
	int smallest = 0;
	m_length < length ? smallest = m_length : smallest = length;
	for (int i = 0; i < smallest; i++)
	{
		newData[i] = m_array[i]; //deep copy to new data
	}
	delete[] m_array; //delete old array
	m_array = nullptr;
	m_array = newData; //make them equal
	m_length = length;
}
#endif