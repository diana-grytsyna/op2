#include "Tetr.hpp"
#include <iostream>
#include <cmath>
using namespace std;
Tetr::Tetr(int a1[3], int b1[3], int c1[3], int d1[3]){
    for(int i=0; i<3; i++){
        a[i] = a1[i];
        b[i] = b1[i];
        c[i] = c1[i];
        d[i] = d1[i];
    }
}
double Tetr::getVolume(){
    int ab[3], ac[3], ad[3];
    //побудова векторів на координатах
    for(int i=0; i<3; i++){
        ab[i] = b[i] - a[i];
        ac[i] = c[i] - a[i];
        ad[i] = d[i] - a[i];
    }
    //знаходимо мішаний добуток
    double volume = fabs(ab[0]*ac[1]*ad[2] + ab[1]*ac[2]*ad[0] + ab[2]*ac[0]*ad[1] - ad[0]*ac[1]*ab[2] - ad[1]*ac[2]*ab[0] - ad[2]*ac[0]*ab[1])/6;
    return volume;
}
void Tetr::print(){
    cout<<"Coordinates\n";
    cout<<"A: "<<a[0]<<", "<<a[1]<<", "<<a[2]<<"\n";
    cout<<"B: "<<b[0]<<", "<<b[1]<<", "<<b[2]<<"\n";
    cout<<"C: "<<c[0]<<", "<<c[1]<<", "<<c[2]<<"\n";
    cout<<"D: "<<d[0]<<", "<<d[1]<<", "<<d[2]<<"\n";
}
