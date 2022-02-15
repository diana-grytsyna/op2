#include <iostream>
#include <fstream>
using namespace std;
void file_out(string name);
ofstream get_file(char symb, string name);
void fill_file(ofstream (*openf)(char, string),char symb,string name);
int split_string(string us_string, string *str_arr);
void newfile(string name1, string name2, int length);
int get_n();
char filemode();
int main() {
    string file_name = "/Users/dianagr/Documents/lab21/lab21/input.txt";
    string new_file2 ="/Users/dianagr/Documents/lab21/lab21/result.txt";
    char symb_mode = filemode();//вибір режиму відкриття файлу
    fill_file(get_file, symb_mode, file_name);//відкриття і запис файлу
    cout<<"File 1: "<<"\n";
    file_out(file_name);//виведення інформації з файлу
    int n = get_n();//кількість слів користувача
    newfile(file_name, new_file2, n);//створення нового файлу
    cout<<"File 2: "<<"\n";
    file_out(new_file2);//виведення інформації з нового файлу
    return 0;
}
void file_out(string name){
    ifstream user_file(name);
    string str;
    if(!user_file){
        cout<<"Cannot open file"<<"\n";
    }else{
    while(!user_file.eof()){
        getline(user_file, str);//читання рядків
        cout<<str<<"\n";
    }
        user_file.close();
    }
}
ofstream get_file(char symb, string name){
    if(symb=='w'){
        ofstream user_file(name, ios::out);//відкрити файл для запису
        return user_file;
    }else{
        ofstream user_file(name, ios::app);//відкрити файл для запису даних в кінець
        return user_file;
    }
}
void fill_file(ofstream (*openf)(char, string),char symb,string name){
    ofstream user_file = openf(symb, name);
    string str =" ";
    if(!user_file){
        cout<<"Cannot open file"<<"\n";
    }else{
        cout<<"Enter smth, to stop press Option+U"<<"\n";
        while(str.find(-62)==string::npos){
            getline(cin, str);
            if(str.find(-62)==string::npos)//умова закінчення введення тексту
                user_file<<str<<"\n";
            else break;
        }
        user_file.close();
    }
    
}
int split_string(string us_string, string *str_arr){
    size_t pos;
    string word;
    int i = 0;//кількість слів
    while((pos=us_string.find(" "))!=string::npos){ //розбиття рядка за пробілами
        word = us_string.substr(0, pos);
        if(word!=""){
            str_arr[i] = word;
            i++;
        }
        us_string.erase(0, pos+1);
        
    }
    return i;
}
void newfile(string name1, string name2, int length){
    ifstream file1(name1);
    ofstream file2(name2);
    string str;
    string text = "";
    while(!file1.eof()){
        getline(file1, str);//читання рядків
        text += str + " ";
    }
    size_t len = text.length()/2;
    string *word_arr = new string[len];//слова у тексті
    int amount = split_string(text, word_arr);//кількість слів у тексті
    string *new_word_arr = new string[amount];//слова, що задовольняють умову
    int k = 0;
    for(int i=0; i<amount-1; i++){
        int counter = 1;//кількість однакових слів
        for(int j=i+1; j<amount; j++){
            if(word_arr[i]==word_arr[j]){
                word_arr[j] = "";
                counter++;
            }
        }
        if(counter>length&&word_arr[i]!=""){
            new_word_arr[k] = word_arr[i];//слова, кількість яких більша за введену користувачем
            k++;
        }
        
    }
    //сортування в порядку зростання довжини
    for(int i=0; i<k; i++){
        for(int j=0; j<k-1; j++){
            if(new_word_arr[j].length()>new_word_arr[j+1].length()){
                string tmp = new_word_arr[j+1];
                new_word_arr[j+1] = new_word_arr[j];
                new_word_arr[j] = tmp;
            }
        }
    }
    //запис інформації в новий файл
    for(int i=0; i<k; i++){
        file2<<new_word_arr[i]<<" ";
    }
    delete []word_arr;
    delete []new_word_arr;
    file1.close();
    file2.close();
}
int get_n(){
    int n;
    cout<<"Enter amount of words";
    cin>>n;
    return n;
}
char filemode(){
    char symb;
    cout<<"Enter w - write in file, a - add text"<<"\n"; //вибір режиму відкриття файлу
    cin>>symb;
    return symb;
}
