//
//  func.cpp
//  lab26
//
//  Created by Діана on 23.05.2022.
//

#include "func.hpp"
#include <iostream>
using namespace std;
string getText(){
    string line = " ";
    string text = "";
    cout<<"Enter smth ";
    while(!empty(line)){
        getline(cin, line);
        if(!empty(line)){
            text += line + " ";
        }
    }
    return text;
}
int spilt_string(string text, string *word_arr){
    size_t pos;
    string word;
    int i=0;
    while((pos=text.find(" "))!=string::npos){
        word = text.substr(0, pos);
        if(!empty(word)){
            word_arr[i] = word;
            i++;
        }
        text.erase(0, pos+1);
    }
    return i;
}
int calculate_words(string *word_arr, string *word_arr2, int i){
int counter_arr = 0;
for(int j=0; j<i; j++){
    if(word_arr[j]!=""){
    int counter = 1;
    for(int k=j+1; k<i; k++){
        if(word_arr[j]==word_arr[k]){
            counter++;
            word_arr[k]="";
        }
    }
        word_arr2[counter_arr] = word_arr[j] + to_string(counter);
        counter_arr++;
    }
}
    return counter_arr;
}
void sort_arr(string *word_arr, int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size-1; j++){
            int num1 = stoi(word_arr[j].substr(word_arr[j].length()-1, word_arr[j].length()));
            int num2 = stoi(word_arr[j+1].substr(word_arr[j+1].length()-1, word_arr[j+1].length()));
            if(num2>num1){
                string tmp = word_arr[j];
                word_arr[j] = word_arr[j+1];
                word_arr[j+1] = tmp;
            }
        }
    }
}
int make_arr(string *sorted_arr, string *word_arr, int size){
    int counter = 0;
    for(int i=0; i<size; i++){
        int num1 = stoi(sorted_arr[i].substr(sorted_arr[i].length()-1, sorted_arr[i].length()));
        string line = sorted_arr[i].substr(0, sorted_arr[i].length()-1);
        for(int j=0;j<num1; j++){
            word_arr[counter] = line;
            counter++;
        }
    }
    return counter;
}

