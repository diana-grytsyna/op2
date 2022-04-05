#include <iostream>
#include "Tetr.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    srand(static_cast<unsigned int>(time(0)));
    Tetr* arr_tetr[5];//масив об'єктів класу Tetr
    double arr_vol[5];
    for(int i=0;i<5; i++){
        //Рандомні координати
    int a1[3] = {rand()%10,rand()%10,rand()%10};
    int b1[3] = {rand()%10,rand()%10,rand()%10};
    int c1[3] = {rand()%10,rand()%10,rand()%10};
    int d1[3] = {rand()%10,rand()%10,rand()%10};
    Tetr tetr(a1,b1,c1,d1);
    arr_tetr[i] = &tetr;//записуємо об'єкт у масив
    arr_vol[i] = arr_tetr[i]->getVolume();//об'єм тетраедра
    arr_tetr[i]->print();
    cout<<"Volume: "<<arr_vol[i]<<"\n";
    }
    double max = arr_vol[0];//визначення найбільшого об'єма
    for(int i=0; i<5; i++){
        if(arr_vol[i]>max){
            max = arr_vol[i];
        }
    }
    cout<<"The largest volume: "<<max<<"\n";
    return 0;
}
