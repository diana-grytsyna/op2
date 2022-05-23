//
//  func.hpp
//  lab26
//
//  Created by Діана on 23.05.2022.
//

#ifndef func_hpp
#define func_hpp
#include <iostream>
using namespace std;
#include <stdio.h>
string getText();
int spilt_string(string us_string, string *word_arr);
int calculate_words(string *word_arr, string *word_arr2, int i);
void sort_arr(string *word_arr, int size);
int make_arr(string *sorted_arr, string *word_arr, int size);
#endif /* func_hpp */
