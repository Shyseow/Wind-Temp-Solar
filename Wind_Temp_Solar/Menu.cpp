#include "Menu.h"

Menu::Menu()
{
    ifstream myfile (filename.c_str()); //input file stream

    if (!myfile)
    {
        cout << "No data file found!!" << endl;
    }else{
    read();
    choice();
    }
}

Menu::Menu(string fn)
{
    filename = fn;
    ifstream myfile (filename.c_str());

    if (!myfile)
    {
        cout << "No data file found!!" << endl;
    }else{
    read();
    choice();
    }
}

void Menu::read()
{
    int day, month, year, hour, minute;
    float s, sr, airt;
    Date date;
    Time time;
    string token, line;
    ifstream myfile(filename.c_str());


    getline(myfile, line); //to skip header information

    // start data loading
    cout << "Loading data......"<< endl;
    cout << endl;
    while (getline(myfile, line))
    {
        stringstream ss(line); // pass line to stream

        // token for the day, month, year, hour, minute input in WAST column
        getline(ss,token, '/'); // Token for day
        day = (atoi(token.c_str()));

        getline(ss,token, '/'); // Token for month
        month = (atoi(token.c_str()));

        getline(ss,token, ' '); // Token for year
        year = (atoi(token.c_str()));

        getline(ss,token, ':'); // Token for hour
        hour = (atoi(token.c_str())); //convert string to int

        getline(ss,token, ','); // Token for minute
        minute = (atoi(token.c_str()));

        //loop through and skip the first 9 column
        for(int i = 0; i<9; i++){
                getline(ss, token, ','); //stop at delimiter ','
        } // end of for loop


        getline(ss, token,','); // Token for wind speed in S column
        s = atof(token.c_str());

        getline(ss,token,','); // Token for Solar Radiation in SR column
        sr = atof(token.c_str()); //convert string to float

        // loop through and move 5 columns
        for(int i = 0; i<5; i++){
                getline(ss, token, ',');
        } // end of for loop

        getline(ss,token,','); // Token for air temperature in T column
        airt = atof(token.c_str());

        // store the temporary object in the vector
        Weather d;
        d = Weather(day, month, year, hour, minute, s, sr, airt, date, time);
        MetData.push_back(d); // add new element at the end of the vector
    } // end of while loop
    myfile.close();
}

////////////////////////////////////////////////////////////////////////////////////////
/// Menu for user to select option and perform different task accordingly to selection
///////////////////////////////////////////////////////////////////////////////////////
void Menu::choice()
{
    // to print out the options if the source document is found
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t                  Menu"                                                                   << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "1 - The average wind speed and average ambient air temperature for a specified month and year." << endl;
    cout << "2 - Average wind speed and average ambient air temperature for each month of a specified year." << endl;
    cout << "3 - Total solar radiation in kWh/m^2 for each month of a specified year."                       << endl;
    cout << "4 - Average wind speed(km/h),average ambient air temperature and total solar radiation in "     <<endl;
    cout << "    kWh/m^2 for each month of a specified year.(print to a file called WindTempSolar.csv)"      << endl;
    cout << "5 - Exit the Program."                                                                          << endl;
    cout << endl;

    int choice = enterOption();

    while (choice != 5)
    {
        switch (choice)
        {
            case 1:
                option1();
                break;
            case 2:
                option2();
                break;
            case 3:
                option3();
                break;
            case 4:
                option4();
                break;
            case 5:
                option5();
                break;
            default:
                cout<< "Please re-enter your selection (1-5): "<<endl;
                break;
        } // end of switch
        choice = enterOption();
    } // end of while loop


}

/////////////////////////////////////////////////////////////
/// Method to validate user input selection for menu option
////////////////////////////////////////////////////////////
int Menu::enterOption()
{
    int tempIn;
    cout << "Enter your selection : " << endl;
    cin  >> tempIn;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout<< endl;
        cout << "Please re-enter your selection (1-5): " << endl;
        cin  >> tempIn;
    }

    return tempIn;
}

////////////////////////////////////////
/// Method to validate user input month
////////////////////////////////////////
int Menu::enterMonth()
{
    int  Month;
    bool flag = false;

    while (flag == false)
    {
        cout << "Please enter a month : "<< endl;
        cin  >> Month;

        if(cin.fail())
        {
            cout << "Please re-enter your selection (1-5) : " << endl;
            cin.clear();
            cin.ignore(10000,'\n');
        } else if (Month < 1 || Month >12){
            cout << "Month range is from 1 to 12."<< endl;
            cin.clear();
            cin.ignore(10000,'\n');
        } else {
            flag = true;
        }// end of if
    } // end of while loop
    return Month;
}

////////////////////////////////////////
/// Method to validate user input year
////////////////////////////////////////
int Menu::enterYear()
{
    int  Year;
    bool flag = false;

    while (flag == false)
    {
        cout << "Please enter year: " << endl;
        cin  >> Year;

        if(cin.fail())
        {
            cout << "Please re-enter your selection : " << endl;
            cin.clear();
            cin.ignore(10000,'\n');
        } else if (Year < 1000){
            cout << "Please enter more than 1000 "<< endl;
            cin.clear();
            cin.ignore(10000,'\n');
        } else {
            flag = true;
        }// end of if
    } // end of while loop
    return Year;
}

////////////////////////////////////////////////////////////////////////////////////////////
/// --- Option 1 --- (Average wind speed and air temperature of a specified month and year)
/// Method to perform calculation, output result and validate user input for year and month
///////////////////////////////////////////////////////////////////////////////////////////
void Menu::option1()
{
    int isYear  = enterYear();
    int isMonth = enterMonth();
    int countSum = 0;
    float tempWindspeedSum = 0;
    float tempAirTempSum   = 0;

    for(int i =0; i < MetData.getPosition(); i++)
    {
        if(MetData.at(i).GetYear() == isYear)
        {
            if(MetData.at(i).GetMonth() == isMonth)
                {
                    tempWindspeedSum += MetData.at(i).GetWindspeed();
                    tempAirTempSum   += MetData.at(i).GetAirTemp();
                    countSum++;
                }// end of inner if loop
        } //end of outer if loop
    }// end of for loop
    if (tempWindspeedSum ==0 && tempAirTempSum==0)
        cout << monthName[isMonth-1] << " " << isYear << " : " << " " << "No Data" << endl;
    else {
        cout << "Average wind speed and ambient air temperature for " << "'" << monthName[isMonth-1]<< " " << isYear<< "'" << ":" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << monthName[isMonth-1]<< " " << isYear << " : " << fixed << showpoint << setprecision(1) << tempWindspeedSum/countSum <<" km/h "
             << "," << fixed << showpoint << setprecision(1) << tempAirTempSum/countSum << " degrees C" <<endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }// end of if loop
}

//////////////////////////////////////////////////////////////////////////////////
/// --- Option 2 --- (Average wind speed and air temperature of a specified year)
/// Method to perform calculation, output result and validate user input for year
/////////////////////////////////////////////////////////////////////////////////
void Menu::option2()
{
    int isYear  = enterYear();
    float avgWindspeed[12]= {0};
    float avgAirTemp[12]  = {0};

    for(int i = 0; i < 12; i++)
    {
        int counts = 0;
        float sumWindspeed = 0, sumAirTemp =0;

        for (int index=0; index< MetData.getPosition(); index++)
            {
                if(MetData.at(index).GetYear() == isYear && MetData.at(index).GetMonth() == (i+1))
                    {
                         sumWindspeed += MetData.at(index).GetWindspeed();
                         sumAirTemp += MetData.at(index).GetAirTemp();
                         counts++;
                    }// end of outer if loop
            }// end of for loop

            if (counts!=0)
                {
                    avgWindspeed[i] = sumWindspeed/counts;
                    avgAirTemp[i]   = sumAirTemp/counts;
                }else{
                    avgWindspeed[i] = 0;
                    avgAirTemp[i]   = 0;
                }// end of if
    }

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Average wind speed & air temperature of the year "<< isYear <<" :" << endl;

    for (int index =0; index < 12; index ++)
    {
        if (avgWindspeed[index] != 0.0000)
            cout << fixed << showpoint << setprecision(1) << setw(10) << monthName[index] << " : "
            << (avgWindspeed[index]) <<" km/h "<<","<< setw(5) << avgAirTemp[index] <<" degrees C"<< endl;
        else
            cout << setw(10) << monthName[index]<< " : " << setw(10) << "No Data" << endl;
    }// end of for loop
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
/// --- Option 3 --- (Total solar radiation in kWh/m2 of a specified year)
/// Method to perform calculation and conversion, output result and validate user input for year
/////////////////////////////////////////////////////////////////////////////////////////////////
void Menu::option3()
{
    int isYear = enterYear();
    float solarRadiation[12] = {0};

    //load the data and store into array.
    for (int i=0;i < 12; i++)
    {
        for (int index=0; index< MetData.getPosition(); index++)
            {
                if(MetData.at(index).GetMonth() == (i+1) && MetData.at(index).GetYear()==isYear)
                    {
                        if(MetData.at(index).GetSolarRadiation() >= 100) //to calculate only solar radiation value >=100
                        {
                            solarRadiation[i] += MetData.at(index).GetSolarRadiation();
                        }

                    }// end of if
            }// end of inner for loop
    }// end of outer for loop

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Total Solar Radiation of " << isYear <<endl;

    for(int index = 0; index < 12; index++){

        if(solarRadiation[index] == 0)
            cout << setw(9) << monthName[index] << " : " << " No Data " << endl;
        else
            cout << setw(9) << monthName[index] << " : " << fixed << showpoint << setprecision(1) << (solarRadiation[index]/6)/1000 << " kWh/m^2" << endl;
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
/// --- Option 4 --- (Average wind speed, air temperature and total radiation in kWh/m2)
/// Method to perform calculation, validate user input for year and output to file "WindTempSolar.csv"
//////////////////////////////////////////////////////////////////////////////////////////////////////
void Menu::option4(){
    int isYear = enterYear();
    float avgAirTemp[12] = {0};
    float avgWindspeed[12]={0};
    float solarRadiation[12]={0};

    for (int i = 0; i<12; i++)
    {
        int counts = 0;
        float sumWindspeed = 0, sumAirTemp = 0;
        for (int index=0; index< MetData.getPosition(); index++)
            {
                if(MetData.at(index).GetYear() == isYear && MetData.at(index).GetMonth()== (i+1))
                        {
                        sumWindspeed += MetData.at(index).GetWindspeed();
                        sumAirTemp   += MetData.at(index).GetAirTemp();
                        solarRadiation[i] =+ MetData.at(index).GetAirTemp();
                        counts++;
                        }//end of if loop
            }// end of inner for loop

            if (counts!=0)
                {
                    avgWindspeed[i] = sumWindspeed/counts;
                    avgAirTemp[i]   = sumAirTemp/counts;
                }else{
                    avgWindspeed[i] = 0;
                    avgAirTemp[i]   = 0;
                }// end of if
    }

    for (int i=0;i < 12; i++)
    {
        for (int index=0; index< MetData.getPosition(); index++)
            {
                if(MetData.at(index).GetMonth() == (i+1) && MetData.at(index).GetYear()==isYear)
                    {
                        if(MetData.at(index).GetSolarRadiation() >= 100) //to calculate only solar radiation value >=100
                        {
                            solarRadiation[i] += MetData.at(index).GetSolarRadiation();
                        }

                    }// end of if
            }// end of inner for loop
    }// end of outer for loop


    ofstream outFile ("WindTempSolar.csv");
    if(outFile.is_open()){
            outFile << isYear << endl;

    bool hasData = false;
        // for each row
        for(int i = 0; i < 12; i++){
            if (avgWindspeed[i] != 0 || avgAirTemp[i] != 0 || solarRadiation[i] !=0){
            outFile << monthName[i] << "," << fixed << showpoint << setprecision(1) << avgWindspeed[i]
            << "," << avgAirTemp[i] << "," << fixed << showpoint << setprecision(1) << (solarRadiation[i]/6)/1000 << endl;
            hasData=true;}
            }// end of if loop

            if (!hasData)
            {
                outFile <<"No Data";
            }

        outFile.close();

        //output success
        cout << "---------------------------------------------------------------" <<endl;
        cout << "File is created successfully, please refer to WindTempSolar.csv" << endl;
        cout << "---------------------------------------------------------------\n" <<endl;

    }
    else{
        cout << "Fail to create file" << endl; // else it will say fail
    }
}

/////////////////////////
/// --- Option 5 ---
/// To exit the program
////////////////////////
void Menu::option5()
{
    exit(0);
}
