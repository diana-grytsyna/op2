//
//  DateOL.cpp
//  lab24
//
//  Created by Діана on 17.04.2022.
//

#include "DateOL.hpp"
#include <iostream>
using namespace std;
DateOL::DateOL(string day, string month, string year){
    this->day = day;
    this->month = month;
    this->year = year;
}
DateOL::DateOL(){
    cout<<"Enter day ";
    cin>>day;
    cout<<"Enter month ";
    cin>>month;
    cout<<"Enter year ";
    cin>>year;
}
void DateOL::setDay(string day){
    this->day = day;
}
void DateOL::setMonth(string month){
    this->month = month;
}
void DateOL::setYear(string year){
    this->year = year;
}
string DateOL::getDay(){
    return day;
}
string DateOL::getMonth(){
    return month;
}
string DateOL::getYear(){
    return year;
}
void DateOL::print(){
    cout<<"Date: "<<day<<"."<<month<<"."<<year<<"\n";
}
int DateOL::daysInMonth(int month, int year){
    int month30[] = {4, 6, 9, 11};//місяці які мають 30 днів
    for(int i=0; i<4; i++){
        if(month==month30[i]) return 30;//перевірка чи місяць має 30 днів
    }
    if(month==2){
        if(year%4==0)return 29;//перевірка на високосний рік
        else return 28;
    }else return 31;//всі інші місяці мають 31 день
}
int DateOL::daysInYear(int year){
    if(year%4==0) return 366;//перевірка на високосний рік
    else return 365;
}
DateOL& DateOL::operator+=(int days){
    int dayInt = stoi(this->day);
    int monthInt = stoi(this->month);
    int yearInt = stoi(this->year);
    if(dayInt+days>this->daysInMonth(monthInt, yearInt)){//додаємо більше днів чим є в місяці
        do{
            days -= this->daysInMonth(monthInt, yearInt)-dayInt;//віднімаємо місяць від числа днів
            dayInt = 0;
            monthInt++;//додаємо місяць який відняли
            if(monthInt==13){//якщо місяців більше чим в році
                monthInt = 1;//перший місяць в році
                yearInt++;//додаємо рік
            }
        }while(dayInt+days>this->daysInMonth(monthInt, yearInt));//перевірка чм більше днів чим є в місяці
    }
    dayInt += days;//додаємо залишок
    string day2 = to_string(dayInt);
    string month2 = to_string(monthInt);
    string year2 = to_string(yearInt);
    if(dayInt<10) day2 = "0"+to_string(dayInt);
    if(monthInt<10) month2 = "0"+to_string(monthInt);
    this->setDay(day2);//встановлення нової дати
    this->setMonth(month2);
    this->setYear(year2);
    return (*this);
}
int operator-(DateOL date1, DateOL date2){
    int res = 0;
    int dayInt1 = stoi(date1.day);
    int monthInt1 = stoi(date1.month);
    int yearInt1 = stoi(date1.year);
    int dayInt2 = stoi(date2.day);
    int monthInt2 = stoi(date2.month);
    int yearInt2 = stoi(date2.year);
    if(yearInt2>yearInt1+1){//якщо різниця між датами більше за 1 рік
        int yearChecker = yearInt2 - 1;
        do{
            res += date2.daysInYear(yearChecker);//підрахунок днів в цілих роках
            yearChecker--;
        }while(yearChecker!=yearInt1);
        int monthCheker1 = monthInt1;
        do{
            res += date1.daysInMonth(monthCheker1, yearInt1);//підрахунок днів в місяцях в першому році
            monthCheker1++;
        }while(monthCheker1<13);
        res -= dayInt1;
        int monthCheker2 = 1;
        while(monthCheker2<monthInt2){
            res += date2.daysInMonth(monthCheker2, yearInt2);//підрахунок днів в місяцях в останньому році
            monthCheker2++;
        };
        res += dayInt2;
    }
    if(yearInt2==yearInt1){//підрахунок в 1 році
        if(monthInt1!=monthInt2){
        int monthChecker = monthInt1;
        do{
            res += date1.daysInMonth(monthChecker, yearInt1);//підрахунок днів в місяцях
            monthChecker++;
        }while(monthChecker<monthInt2);
        res -= dayInt1;
        res += dayInt2;
            
        }else res = dayInt2 - dayInt1;//різниця між днями, якщо в одному місяці
    }
    if(yearInt1+1==yearInt2){//підрахунок між сусідніми роками
        int monthCheker1 = monthInt1;
        do{
            res += date1.daysInMonth(monthCheker1, yearInt1);//підрахунок днів в місяцях в першому році
            monthCheker1++;
        }while(monthCheker1<13);
        res -= dayInt1;
        int monthCheker2 = 1;
        while(monthCheker2<monthInt2){
            res += date2.daysInMonth(monthCheker2, yearInt2);//підрахунок днів в місяцях в останньому році
            monthCheker2++;
        };
        res += dayInt2;
    }
    return res;
    
}
string DateOL::getSeason(){
    int monthInt = stoi(month);
    //визначення пори року за місяцем
    if(monthInt<=2||monthInt==12)return "winter";
    else if(monthInt<=5) return "spring";
    else if(monthInt <=8) return "summer";
    else return "autumn";
}
