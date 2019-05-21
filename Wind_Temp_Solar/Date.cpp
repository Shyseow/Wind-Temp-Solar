#include "Date.h" //include header file
#include <iostream>
#include <cstdlib>

using namespace std;

Date::Date() //default constructor
{
    day=1;
    month=5;
    year=2001;
}

Date::Date(int dd,int mm,int yy) //parameterized constructor
{
    day = dd;
    month = mm;
    year = yy;

}

//Setters
void Date::SetDay(int dd) //returnType class name::MethodName(vars)
{
    day=dd;
}

void Date::SetMonth(int mm)
{
    month=mm;
}

void Date::SetYear(int yy)
{
    year=yy;
}

void Date::SetDate(int dd, int mm, int yy)
{
    day   = dd;
    month = mm;
    year  = yy;
}

int Date::GetDay() const
{
    return day;
}

int Date::GetMonth() const
{
    return month;
}

int Date::GetYear() const
{
    return year;
}


ostream& operator<<(ostream& osObject, const Date& date)//overloading of output operator
{
   osObject<<date.GetDay()<<"/"<<date.GetMonth()<<"/"<<date.GetYear();

   return osObject;
}

istream& operator>>(istream& isObject,Date& date)//overloading of input operator
{
    int dd,mm,yy;
    isObject>>dd>>mm>>yy; //to take values from the stream

    date.SetDay(dd);
    date.SetMonth(mm);
    date.SetYear(yy);

    return isObject;
}

