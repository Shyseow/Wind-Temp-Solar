/* The Date class Header (Date.h) */
//---------------------------------------------------------------------------------
	/**
	 * @class  Date
     * @file   Date.h
     * @brief  Declaration for function and variables; and macro definition is made
     *         in this class. This class also hold the value of day, month and year
     *
	 * @author Seow Hui Yin
	 * @version 1.0
	 * @date submission : 25/06/2018
     */
//---------------------------------------------------------------------------------
#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
//---------------------------------------------------------------------------------
#include <iostream>
#include <cstdlib>

using namespace std;

//Date class declaration
class Date
{
public:
    // Declare member function prototypes
    //--constructors
    /**
     * @brief  Default constructor with no parameters to initialize the variables
     *         To set the initial value of the data member variables
     *         with default value
     */
    Date();

    /**
     * @brief  Parameterized constructor with parameters to initialize the variables
     *         with given value in Date class
     *         To set the initial value of the member variables with given value
     *
     * @param  integer - int of day, month year
     *
     */
    Date(int dd, int mm, int yy);

    //--setters
    /**
	 * @brief Set the value of day, set day variable
	 *
	 * @param integer - int of day
	 *
	 * @return void
	 *
	 */
    void SetDay(int dd);

    /**
	 * @brief Set the value of month, set month variable
	 *
	 * @param integer - int of month
	 *
	 * @return void
	 *
	 */
    void SetMonth(int mm);

    /**
	 * @brief Set the value of year, set year variable
	 *
	 * @param integer - int of year
	 *
	 * @return void
 	 *
	 */
    void SetYear(int year);

    /**
	 * @brief Set the value of Date in dd/mm/yy
	 *
	 * @param Date : int of day,month,year
	 *
	 * @return void
	 *
	 */
    void SetDate(int dd, int mm, int yy);

    //--getters
    /**
	 * @brief Get the value of day
	 *
	 * @return value of day variable in int
	 *
	 */
    int GetDay() const;

    /**
	 * @brief Get the value of month
	 *
	 * @return value of month variable in int
	 *
	 */
    int GetMonth() const;

    /**
	 * @brief Get the value of year
	 *
	 * @return value of year variable in int
	 *
	 */
    int GetYear() const;

private:
    // private data members (variables)
    int day;
    int month;
    int year;

};

  /**
    * @brief  Overload output operator
    *
    *         To allows other class to access the private member in this class
    *
    * @overload <<(ostream& osObject, const Date& date)
    *
    */
ostream& operator << (ostream& osObject, const Date& date);

  /**
    * @brief  Overload input operator
    *
    *         To allows other class to access the private member in this class
    *
    * @overload >> (istream& isObject, Date& date)
    *
    */
istream& operator >> (istream& isObject, Date& date);

#endif // DATE_H_INCLUDED


