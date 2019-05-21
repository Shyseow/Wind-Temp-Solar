/* The Vector class Header (Vector.h) */
//---------------------------------------------------------------------------------
	/**
	 * @class Vector
     * @file  Vector.h
     * @brief  A templated Vector that replicate as a STL <vector> class to store
	 *         the elements of Weather’s data contiguously.
	 *         Declaration for function and variables; and macro definition is made
     *         in this class.
     *
	 * @author Seow Hui Yin
	 * @version 1.0
	 * @date submission : 25/06/2018
     */
//---------------------------------------------------------------------------------
#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
//---------------------------------------------------------------------------------
#include <iostream>

using namespace std;

template <class T> // for templated class

//Vector class declaration
class Vector
{
public:
    // Declare member function prototypes
    //--constructor
    /**
     * @brief  default constructor to initialize the vector to capture the obejcts to be stored
     *
     *         to create a new vector
     *
     *
     */
    Vector();

    /**
     * @brief  to get the object at the specified position of the vector T
     *
     *         return the specified object
     *
     * @return object
     */
    T& at(int i);

    /**
     * @brief  to add new element into the vector T
     *
     *         to push the given object to the last in the vector
     *
     * @return void
     */
    void push_back(const T& elem);

    /**
     * @brief  to return the position of the last element in the vector
     *
     *         to return an integer value of the postion of the last element in the vector
     *
     * @return int, position of the last element
     */
    int getPosition();

    /**
     * @brief  to return the size of the vector T
     *
     *
     *
     * @return int, the size of the array
     */
    int getCapacity();


    /**
     * @brief   to check if the vector is full and return a boolean value
     *
     *          to check the vector is empty by checking if the point of the last element is at the end of the vector
     *
     * @return bool
     */
    bool isFull();

    /**
     * @brief  to check if the vector is empty and return a boolean value
     *
     *         to check the vector is empty by checking if the point of the last element is at the start of the vector
     *
     * @return bool
     */
    bool isEmpty();

    /**
     * @brief  to resize the vector T
     *
     *         to resize the vector by passing in a new size
     *
     * @return void
     */
    void resize(int newSize);

     /**
      * @brief  to create vector T
      *
      *         to create a vector of a default size
      *
      * @return void
      */
    void create(int size);

    /**
     * @brief  to delect the elements in the vector T
     *
     *
     *
     * @return void
     */
    void clear(); // clear private variables

private:
    //--pointers
    T* list;
    T* start;
    T* end;
    // private data members (variables)
    int position;     // the position of an element
    int capacity;    // the size of the vector/array
};

template <class T>
Vector<T>::Vector()
{
    clear();
    create(2);
}

template <class T>
void Vector<T>::clear()
{
    list    = NULL;
    start   = NULL;
    end     = NULL;
    position= 0;
    capacity= 0;
}

template <class T>
void Vector<T>::push_back(const T& elem)
{
    //if the vector/array reaches the end, it needs to be resized
    if (position == (capacity-1)) //check if we need to resize
    {
        resize(capacity*2); // to ensure the size is enough (can change to any value)
    }

    *end = elem; // assign value
    end++;
    position++;
}

template <class T>
int Vector<T>::getCapacity()
{
    // to get the size of the vector/array
    return capacity;
}

template <class T>
int Vector<T>::getPosition()
{
    // to get the position of particular element in the vector/array
    return position;
}

template <class T>
void Vector<T>::create(int size)
{
    list  = new T[size];
    start = list;
    end   = list;
    capacity= size;
}

template <class T>
bool Vector<T>::isEmpty() //check whether the vector is empty
{
    return (position == 0);
}

template <class T>
bool Vector<T>::isFull() //check whether the vector is full
{
    return (position == capacity);
}

template <class T>
void Vector<T>::resize(int newSize)
{
    T* newList = new T[newSize]; // create a new list/vector/array with bigger size
    T* newListPointer = newList; // pointer to the new array
    T* oldListPointer = list; // pointer to the old array

    while(oldListPointer!=(list+position)) //while-loop until all values are copied, "list+position" is the end of the array
    {
        *(newListPointer) =*(oldListPointer); // copy the value from the old list to the new list
        newListPointer++; // move to next element
        oldListPointer++; // move to next element
    }

    start   = newList;  // make the start pointer points to the new list
    end     = newList+position; // make the end pointer points to the new array
    capacity= newSize;

    delete[] list; //delete old array. prevent memory leak
    list=newList; //assign list pointer to the new array
}

template <class T>
T& Vector<T>::at(int i) //return a reference to the element at position i in the vector
{
    if (i>=0 && i < position)
    {
        return list[i];
    }
    return list[0];
}

#endif // VECTOR_H
