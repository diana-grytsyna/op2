//
//  main.cpp
//  lab26
//
//  Created by Діана on 16.05.2022.
//

#include <iostream>
#include "Tree.hpp"
#include "func.hpp"
using namespace std;
int main() {
    string text = getText();
    string *word_arr = new string[(int)text.length()/2];
    int i = spilt_string(text, word_arr);
    string *word_arr2 = new string[i];
    int counter_arr = calculate_words(word_arr, word_arr2, i);
    sort_arr(word_arr2, counter_arr);
    cout<<"Sorted"<<endl;
    for(int j=0; j<counter_arr; j++){
        cout<<word_arr2[j]<<endl;
    }
    string *result_arr = new string[(int)text.length()/2];
    int amount = make_arr(word_arr2, result_arr, counter_arr);
    Tree BinaryTree;
    Node* root = BinaryTree.makeTree(result_arr, 0, amount);
    cout<<endl;
    BinaryTree.printBT("", root, false);
    cout<<endl;
    BinaryTree.levelOrder(root, result_arr, 0);
    cout<<"RESULT"<<endl;
    cout<<endl;
    BinaryTree.printBT("", root, false);
    return 0;
}

