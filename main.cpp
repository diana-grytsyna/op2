#include <iostream>
#include <fstream>
#include "func.hpp"
using namespace std;
int main() {
    string filename = "/Users/dianagr/Documents/lab22/lab22/trains.dat";
    string filename2 = "/Users/dianagr/Documents/lab22/lab22/result.dat";
    create_file(filename);//запис інформації у файл
    output_file(filename);//виведення першого створеного файлу
    create_new_file(filename, filename2);//створення 2 файлу на основі даних, які були введені
    cout<<"\n\nWINTER LIST";
    output_file(filename2);//виведення результату
    return 0;
}
