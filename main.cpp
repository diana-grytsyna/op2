//
//  main.cpp
//  lab24
//
//  Created by Діана on 17.04.2022.
//

#include <iostream>
#include "DateOL.hpp"
using namespace std;
int main() {
    DateOL Date("12", "12", "2020");
    DateOL Date2;
    DateOL Date3("08", "07", "2015");
    Date.print();
    Date2.print();
    Date3.print();
    Date += 9;//Збільшення дати 1 на 9 днів
    cout<<"date1 after changing\n";
    Date.print();
    Date2 += 14;//Збільшення дати 2 на 14 днів
    cout<<"date2 after changing\n";
    Date2.print();
    int res = Date - Date2;//Тривалість інтервалу між датами
    cout<<"Result: "<<res<<"\n";
    string season = Date3.getSeason();//пора року, якій відповідає дата
    cout<<"date3 Season: "<<season<<"\n";
    return 0;
}
