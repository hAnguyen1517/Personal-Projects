// Calculate_Current_Date_Time.cpp : This file contains the 'main' function. Program execution begins and ends there.
// /This program calculates current date and time base on MST time zone, and displays on the bottom right  of user's computer screen
//NOTE: DAYLIGHT SAVING ----> hours = hours - 6;

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;

// Check the leap year by using if else statements.]
// Return 0 --> not a leap year, Return 1--> Leap year
int isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1;
            }
            else {
                return 0;
            }
        }
        else {

            return 1;
        }
    }
    else {
        // Not a leap year  
        return 0;
    }

}

int getMonth(int day, int year) {
    int month = 0; // 0 - means start at January
    int i = 1;  // index start at 0 has the element of 1 which is January.
    while (day >= 0) {
        month += 1;
        i += 1;
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
            day = day - 31;
        }
        // Check leap year for Febuary. 
        else if (i == 2) {
            if (isLeapYear(year))
                day = day - 29;
            else
                day = day - 28; // not a leap year.
        }
        // Check if 
        else {
            day = day - 30;
        }
        //i += 1;
    }
    return month;
}

// 
int getDay(int month, int year) { // add current month and current year, we will have day.
    int day = 0;  // 
    int i = 1; // start with January. 
    for (i = 1; i < month; ++i) {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
            day = day + 31;
        }
        else if (i == 2) {
            // Check if it is a leap year.
            if (isLeapYear(year))
                day = day + 29;
            else
                day = day + 28; // not a leap year.
        }
        else {
            day = day + 30; //leftover months after calculating from line 62 to 67.
        }
    }
    return day; // will give us total days have passed in a current month. 
}

int main()
{
    //Setup CONST variables
    const int DAY_IN_SECONDS = 86400;
    const int SECONDS_IN_HOURS = 3600;
    const int SECONDS_IN_MINUTES = 60;
    const int YEARS = 24 * 60 * 60 * 365;
    const int DAY = 24 * 60 * 60;
    // Declare variables.
    int hours;
    int minutes;
    string AM_or_PM = "AM"; //assume the time will be AM, then later will change to PM


    long int seconds = static_cast<long int> (time(NULL)); //Total time in seconds.

    // Calculate the years. 
    int years = seconds / YEARS + 1970;

    //Calculate days.
    long int days = seconds / DAY;   //use long int bc it is the long number. 

    //Calculate the total days from 1970 till now. 
    double numDays = seconds / days;


   //Calculate seconds, hour, minutes.
    seconds = seconds % DAY_IN_SECONDS;
    hours = seconds / SECONDS_IN_HOURS;
    minutes = (seconds % SECONDS_IN_HOURS) / SECONDS_IN_MINUTES;

    // Convert UNIX time to local timezome which is Denver.
    hours = hours - 7;  // Denver timezone = GMT -6
    //Hint: For daylight saving ---> 
    //hours = hours - 6;

    // Use if statement to calculate the negative time.
    if (hours < 0)  // if negative hour.
        hours = hours + 24; // add a day (24 hours) to become positive hours.

    if (hours > 12)
    {
        hours = hours - 12;  // this step will tell us time in pm.
        AM_or_PM = "PM";
    }
    //Promt user input for seconds and hour, minutes.
    //cout << seconds << endl;
    cout << hours << ":" << setw(2) << setfill('0') << minutes << " " << AM_or_PM; //Use setw and setfill to format integers to two digits in minutes. 

    cout << endl;
    // Calculate how many leaps year day from 1970 until now by using for loop.
    int total = 0;
    for (int i = 1970; i < years; i++) {
        if (isLeapYear(i) == 1) { // if it is a leap year, we add 1.
            total += 1; // 
        }
    }
    // currDay : how many days have passed from current year to 1970.
    int currDay = days - (years - 1970) * 365 - total;

    // Use current month data to calculate current days. 
    int month = getMonth(currDay, years);
    int day = getDay(month, years); // ex 31 + 28 = 59, current month - 59 = result, then +1 = current date. 
    cout << month << "/" << currDay - day + 1 << "/" << years << endl; // +1 to get the current date

    return 0;
}


