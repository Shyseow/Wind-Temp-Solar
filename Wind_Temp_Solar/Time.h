/* The Time class Header (Time.h) */
//---------------------------------------------------------------------------------
	/**
	 * @class  Time
     * @file   Time.h
     * @brief  Declaration for function and variables; and macro definition is made
     *         in this class. This class also hold the value of hours and minutes
     *
	 * @author Seow Hui Yin
	 * @version 1.0
	 * @date submission : 25/06/2018
     */
//---------------------------------------------------------------------------------
#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
//---------------------------------------------------------------------------------

#include <iostream>

using namespace std;

//Time class declaration
class Time
{
public:
    // Declare member function prototypes
    //--constructors
    /**
     * @brief  Default constructor with no parameters to initialize the variables
     *         To set the initial value of the data member variables
     *         with default value
     */
    Time();

    /**
     * @brief  Parameterized constructor with parameters to initialize the variables
     *         with given value in Date class
     *         To set the initial value of the member variables with given value
	 *
     * @param  integer - int of minutes and hours
     *
     */
    Time(int mm, int hh);

    //--setters
    /**
	 * @brief Set the value of minutes, set minutes variable
	 *
	 * @param integer - int of minutes
	 *
	 * @return void
	 *
	 */
    void SetMinute(int mm);

    /**
	 * @brief Set the value of hours, set hours variable
	 *
	 * @param integer - int of hours
	 *
	 * @return void
	 *
	 */
    void SetHour(int hh);

    /**
	 * @brief Set the value of Time in mm:hh
	 *
	 * @param Date : int of minutes and hours
	 *
	 * @return void
	 *
	 */
    void SetTime(int mm, int hh);

    //--getters
    /**
	 * @brief Get the value of minutes
	 *
	 * @return value of minutes variable in int
	 *
	 */
    int GetMinute() const;

    /**
	 * @brief Get the value of hours
	 *
	 * @return value of hours variable in int
	 *
	 */
    int GetHour() const;

private:
    // private data members (variables)
    int minute;
    int hour;

};

  /**
    * @brief  Overload output operator
    *
    *         To allows other class to access the private member in this class
    *
    * @overload <<(ostream& osObject, const Time& time)
    *
    */
ostream& operator<<(ostream& osObject, const Time& time);

  /**
    * @brief  Overload input operator
    *
    *         To allows other class to access the private member in this class
    *
    * @overload >> (istream& isObject, Time& time)
    *
    */
istream& operator>>(istream& isObject,Time& time);


#endif // TIME_H_INCLUDED
