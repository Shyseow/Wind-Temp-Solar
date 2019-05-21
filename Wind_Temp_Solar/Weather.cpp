#include "Weather.h"
#include "Time.h"
#include "Date.h"

Weather::Weather()
{
    windSpeed      = 0;
    solarRadiation = 0;
    Atemp          = 0;
}

Weather::Weather(int dd, int mth, int yy, int hh, int mm, float Ws, float SR, float T, Date date,Time time):date(dd,mth,yy),time(hh, mm)
{
    windSpeed      = Ws;
    solarRadiation = SR;
    Atemp          = T;
}

void Weather::SetWindspeed(float Ws)
{
    windSpeed = Ws;
}
void Weather::SetSolarRadiation(float SR)
{
    solarRadiation = SR;
}
void Weather::SetAirTemp(float T)
{
    Atemp = T;
}
void Weather::SetAll(int dd, int mth, int yy, int mm, int hh, float Ws, float SR, float T)
{
    date.SetDate(dd,mth,yy);
    time.SetTime(hh, mm);
    windSpeed      = Ws;
    solarRadiation = SR;
    Atemp        = T;
}

void Weather::SetTime(Time t)
{
    time = t;
}

void Weather::SetDate(Date d)
{
    date = d;
}


float Weather::GetWindspeed() const
{
    return windSpeed;
}
float Weather::GetSolarRadiation() const
{
    return solarRadiation;
}

float Weather::GetAirTemp() const
{
    return Atemp;
}


int Weather::GetMonth() const
{
    return date.GetMonth();
}

int Weather::GetYear() const
{
    return date.GetYear();
}

Date Weather::GetDate() const //Date&
{
    return date;
}

Time Weather::GetTime() const
{
    return time;
}

ostream &operator << (ostream& os,const Weather &m)
{
    os << m.GetWindspeed() << m.GetSolarRadiation() << m.GetAirTemp() << m.GetDate() << m.GetTime();
    return os;
}

istream &operator >> (istream& input, Weather &m)
{
    int dd,mth,yy,mm,hh;
    float Ws,SR,T;
    Date d;
    Time t;

    input >>dd>>mth>>yy>>hh>>mm>>Ws>>SR>>T>>d>>t;

    m.SetWindspeed(Ws);
    m.SetSolarRadiation(SR);
    m.SetAirTemp(T);
    m.SetDate(d);
    m.SetTime(t);

    return input;
}

/*ostream &operator << (ostream& osObject,const Data &data) //overloading of output operator
{
    osObject << data.GetWindspeed() << data.GetSolarRadiation() << data.GetAirTemp() ;//<< data.GetDate() << data.GetTime();
    return osObject;
}

istream &operator >> (istream& isObject, Data &data)
{
    float Ws,SR, T;
   // date(dd,m,yy),time(hh, mm);
    isObject >> Ws >> SR >> T;// >> d >> t;

    data.SetWindspeed(Ws);
    data.SetSolarRadiation(SR);
    data.SetAirTemp(T);
    //data.SetDate(d);
    //data.SetTime(t);
    return isObject;
}*/


