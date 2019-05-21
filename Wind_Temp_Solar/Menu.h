/* The Menu class Header (Menu.h) */
//---------------------------------------------------------------------------------
	/**
	 * @class  Menu
     * @file   Menu.h
     * @brief  This class takes in user's file and produce output.
	 *	       This class perform the declaration and runs different action according to user's selection.
     *         Declaration for function and variables; and macro definition also is made
     *         in this class.
 	 *
	 * @author Seow Hui Yin
	 * @version 1.0
	 * @date submission 25/06/2018
	 *
     */
//---------------------------------------------------------------------------------
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
//---------------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
//---------------------------------------------------------------------------------
#include "Vector.h"
#include "Time.h"
#include "Weather.h"
#include "Date.h"

using namespace std;

//Menu class declaration
class Menu
{
    public:
        // Declare member function prototypes
        //-- default constructors
        /**
         * @brief  Default constructor with no parameters
	     *
         *         to initialize the ifstream object that is not corresponding to any file
         *
         */
        Menu();

        /**
         * @brief  Get a filename from user.
         *
         *         to initialize the ifstream object that is corresponding with the file location
         *         by filename
         *
         */
        Menu(string fn);

        /**
         * @brief  Get an integer value from user for the menu option
         *
         *         to validate the user entered a valid value within the restraint selection
         *
         * @return int, value for menu option
	     *
         */
        int  enterOption();

        /**
         * @brief  Get an integer value from user for the specified month
         *
         *         to validate if the user entered a valid value within the range of month
         *
         * @return integer - int of month
	     *
         */
        int  enterMonth();

        /**
         * @brief  Get an integer value from user for the year in Query class
         *
         *         to validate if the user enters a valid value within the constrained range and if that is a integer
         *
         * @return integer - int of year
	     *
         */
        int  enterYear();

        /**
         * @brief  Load and read the data file; and store in the Vector
         *
         *         to validate the file and load the data into the Vector to perform menu task
         *
         * @return void
	     *
         */
        void read();

        /**
         * @brief  Print the menu and ask the user to enter an option
         *
         * @return void
	     *
         */
        void choice();

        /**
         * @brief  Prompt the user to enter month and year
	     *         Calculate the average windSpeed and the airTemperature
	     *         Read and calculate value of average of windSpeed and airTemperature in the Vector, and print output
         *
         * @return void
	     *
         */
        void option1();

        /**
         * @brief  Prompt the user to enter year
	     *         Calculate the average windSpeed and the airTemperature
	     *         Read and calculate value of average of windSpeed and airTemperature in the Vector, and print output
         *
         * @return void
	     *
         */
        void option2();

        /**
         * @brief  Prompt the user to enter year
	     *         Calculate the total solarRadiation and convert to kWh/m2 unit
	     *         Read and calculate value of total solarRadiation in the Vector, and print output in kWh/m2
         *
         * @return void
	     *
         */
        void option3();


        /**
         * @brief  Prompt the user to enter year
	     *	   Calculate the average windSpeed,airTemperature and total solarRadiation
	     *         Read and calculate value of average windSpeed,airTemperature and total solarRadiation
         *         and output to file "WindTempSolar.csv"
         *
         * @return void
         */
        void option4();

       /**
         * @brief  Exit the program
	     *
         *
         * @return void
         */
        void option5();


    private:
        Vector<Weather> MetData;
        string monthName[12] = {"January", "February", "March", "April", "May", "June","July", "August","September", "October", "November", "December"};
        string filename = "MetData_Mar01-2014-Mar01-2015-ALL.csv";
};

#endif //
