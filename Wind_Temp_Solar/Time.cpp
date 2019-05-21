#include "Time.h" //include header file
#include <iostream>
#include <cstdlib>

using namespace std;

Time::Time() //default constructor
{
    minute = 0;
    hour = 0;
}

Time::Time(int mm,int hh) //parameterized constructor
{
    minute = mm;
    hour = hh;

}

//Setters
void Time::SetMinute(int mm) //returnType class name::MethodName(vars)
{
    minute = mm;
}

void Time::SetHour(int hh)
{
    hour = hh;
}

void Time::SetTime(int mm, int hh)
{
    minute = mm;
    hour   = hh;
}

//Getters
int Time::GetMinute() const
{
    return minute;
}

int Time::GetHour() const
{
    return hour;
}

ostream& operator<<(ostream& osObject, const Time& time)//overloading of output operator
{
   osObject<<time.GetMinute()<<":"<<time.GetHour();

   return osObject;
}

istream& operator>>(istream& isObject,Time& time)//overloading of input operator
{
    int mm,hh;
    isObject>>mm>>hh; //to take values from the stream

    time.SetMinute(mm);
    time.SetHour(hh);

    return isObject;
}
