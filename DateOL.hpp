//
//  DateOL.hpp
//  lab24
//
//  Created by Діана on 17.04.2022.
//

#ifndef DateOL_hpp
#define DateOL_hpp
#include <iostream>
#include <stdio.h>
using namespace std;
class DateOL{
    string day, month, year;
public:
    DateOL(string day, string month, string year);
    DateOL();
    void setDay(string day);
    void setMonth(string month);
    void setYear(string year);
    string getDay();
    string getMonth();
    string getYear();
    void print();
    int daysInMonth(int month, int year);
    int daysInYear(int year);
    string getSeason();
    DateOL& operator+=(int days);
    friend int operator-(DateOL date1, DateOL date2);
   
};
#endif /* DateOL_hpp */
