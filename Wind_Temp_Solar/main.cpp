#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

#include "Date.h"
#include "Time.h"
#include "Weather.h"
#include "Vector.h"
#include "Menu.h"

using namespace std;

int main()
{

    string filename = "MetData_Mar01-2014-Mar01-2015-ALL.csv";
    Menu test(filename);

    return 0;
}

