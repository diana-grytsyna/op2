
#include "func.hpp"
#include <iostream>
#include <fstream>
struct Trains{
    string day,
    number,
    departure,
    arrival,
    dep_time,
    arr_time;
};
ofstream get_file(string filename){
    ifstream read(filename);
    if(read.peek() == EOF) {//перевірка чи файл пустий
        read.close();
        ofstream file_b(filename, ios::binary);
        return file_b;
    }else{
        read.close();
        cout<<"There is already some information in the file, to add something enter a, to rewrite it press enter ";
        string add;
        getline(cin, add);//вибір відкрити файл в режимі дозапису чи перезаписати
        if(add=="a"){
             ofstream file_b(filename, ios::app);
             return file_b;
        }else{
            ofstream file_b(filename, ios::binary);
            return file_b;
        }
    };
    
}
void create_file(string filename){
    ofstream file_b = get_file(filename);//відкриття файлу в обраному режимі
    Trains train;
    string days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    for(int i=0; i<7; i++){//створення руху поїздів на кожний день
    string skip="";
    cout<<"To add trains to "<<days[i]<<" enter a, to skip press enter ";
    getline(cin, skip);
    if(!empty(skip)){//перевірка чи додається інформація
        int num;
        cout<<"Amount ";
        cin>>num;//кількість поїздів в 1 день
        for(int j=0; j<num; j++){
            train.day = days[i];
            cin.ignore();
            cout<<"Enter train number ";
            getline(cin, train.number);
            cout<<"Enter departure ";
            getline(cin, train.departure);
            cout<<"Enter arrival ";
            getline(cin, train.arrival);
            cout<<"Enter departure time ";
            getline(cin, train.dep_time);
            cout<<"Enter arrival time ";
            getline(cin, train.arr_time);
            file_b.write((char*)&train, sizeof(Trains));//запис інформації про 1 поїзд у файл
         }
       }
    }
    file_b.close();
}
void output_file(string filename){
    Trains train;
    cout<<"\n\nList of trains\n";
    string days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    for(int i=0; i<7; i++){
    cout<<"\nTrains for "<<days[i]<<"\n";
        ifstream file_b(filename, ios::binary);
    while(file_b.read((char*)&train, sizeof(Trains))){
        if(train.day==days[i]){//сортування поїздів по дням тижня
        cout<<train.number<<" "<<train.departure<<"-"<<train.arrival<<" : "<<train.dep_time<<" - "<<train.arr_time<<"\n";
        }
    }
        file_b.close();
    }
}

void create_new_file(string file1, string file2){
    Trains train;
    ifstream file_b1(file1, ios::binary);//відкриття для читання з файла
    ofstream file_b2(file2, ios::binary);//відкриття для запису в файл
    int time;
    string dep_time;
    while(file_b1.read((char*)&train, sizeof(Trains))){
        dep_time = train.dep_time;//отримання інформації про час відправлення
        time = stoi(dep_time.erase(2, string::npos));
        if(time<=10||time>=18){//перевірка чи час задовольняє умову завдання
            file_b2.write((char*)&train, sizeof(Trains));//додавання поїзда в новий файл
        }
        
    }
    file_b1.close();
    file_b2.close();
}
