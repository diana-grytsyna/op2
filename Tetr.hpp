#ifndef Tetr_hpp
#define Tetr_hpp

#include <stdio.h>
class Tetr{
    int a[3], b[3], c[3], d[3];
public:
    Tetr(int a1[3], int b1[3], int c1[3], int d1[3]);
    double getVolume();
    void print();
   
};
#endif /* Tetr_hpp **/
