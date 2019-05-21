/* The Weather class Header (Weather.h) */
//---------------------------------------------------------------------------------
	/**
	 * @class  Weather
     * @file   Weather.h
     * @brief  To represent the instances of weather.
	 *         Declaration for function and variables; and macro definition is
	 *         made in this class.
	 *         Hold the value of own member variable(windspeed,solar radiation, air temperature)
	 *         and Date and Time objects.
	 *
	 * @author Seow Hui Yin
	 * @version 1.0
	 * @date submission : 25/06/2018
     */
//---------------------------------------------------------------------------------
#ifndef WEATHER_H_INCLUDED
#define WEATHER_H_INCLUDED
//---------------------------------------------------------------------------------
#include "Time.h"
#include "Date.h"
#include <iostream>

using namespace std;

//Weather class declaration
class Weather
{
public:
    // Declare member function prototypes
    //--constructors
    /**
     * @brief  Default constructor with no parameters to initialize the variables
     *         To set the initial value of the data member variables
     *         with default value
     */
    Weather();

    /**
     * @brief  Parameterized constructor with parameters to initialize the variables
     *         with given value in Weather class
     *         To set the initial value of the member variables with given value
     *
     * @param  int    : day,month,year,hours,minutes
     *         float  : windspeed,solar radiation, air temperature
     *         object : Date date,Time time
     *
     */
    Weather(int dd, int m, int yy, int hh, int mm, float Ws, float SR, float T, Date date,Time time);

    //--setters
    /**
	 * @brief Set the value of windspeed, set windspeed variable
	 *
	 * @param float - float of windspeed
	 *
	 * @return void
	 *
	 */
    void SetWindspeed(float Ws);

    /**
	 * @brief Set the value of solar radiation, set solar radiation variable
	 *
	 * @param float - float of solar radiation
	 *
	 * @return void
	 *
	 */
    void SetSolarRadiation(float SR);

    /**
	 * @brief Set the value of air temperature, set air temperature variable
	 *
	 * @param float - float of air temperature
	 *
	 * @return void
	 *
	 */
    void SetAirTemp(float T);

    /**
	 * @brief Set the value for all date,time,windspeed,solar radiation, air temperature
	 *
	 * @param  All - int    : day,month,year,hours,minutes
     *               float  : windspeed,solar radiation, air temperature
     *               object : Date date,Time time
     *
	 * @return void
	 *
	 */
    void SetAll(int dd, int m, int yy, int mm, int hh, float Ws, float SR, float T);

    /**
     * @brief  Set the value of Time object
     *
     *
     * @return void
     */
    void SetTime(Time t);

    /**
     * @brief  Set the value of Date object
     *
     *
     * @return void
     */
    void SetDate(Date d);

    //--getters
    /**
	 * @brief Get the value of windspeed
	 *
	 * @return value of windspeed variable in float
	 *
	 */
    float GetWindspeed() const;

    /**
	 * @brief Get the value of solar radiation
	 *
	 * @return value of solar radiation variable in float
	 *
	 */
    float GetSolarRadiation() const;

    /**
	 * @brief Get the value of air temperature
	 *
	 * @return value of air temperature variable in float
	 *
	 */
    float GetAirTemp() const;

    /**
     * @brief  Get the month value from the Date object
     *
     * @return value of the month value in int of the Date object
     */
    int GetMonth() const;

     /**
      * @brief  Get the year value from the Date object
      *
      * @return value of the year value in int of the Date object
      */
    int GetYear() const;

     /**
      * @brief  Get Date object
      *
      * @return Time, Date object
      */
    Date GetDate() const;

     /**
      * @brief  Get Time object
      *
      * @return Time, Time object
      */
    Time GetTime() const;

    private:
    // private data members (variables)
        float windSpeed;
        float solarRadiation;
        float Atemp;
        Date date;
        Time time;
};

  /**
    * @brief  Overload output operator
    *
    *         To allows other class to access the private member in this class
    *
    * @overload <<(ostream& osObject, const Weather &m)
    *
    */
ostream& operator << (ostream& osObject, const Weather &m);


  /**
    * @brief  Overload input operator
    *
    *         To allows other class to access the private member in this class
    *
    * @overload >> (istream& isObject, Weather &m)
    *
    */
istream& operator >> (istream& isObject, Weather &m); //overload input operator


#endif // WEATHER_H_INCLUDED
