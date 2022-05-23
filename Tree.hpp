//
//  Tree.hpp
//  lab26
//
//  Created by Діана on 16.05.2022.
//

#ifndef Tree_hpp
#define Tree_hpp
#include <iostream>
#include <stdio.h>
using namespace std;
struct Node{
    string data;
    Node *left, *right;
    Node(string x): data(x), left(NULL), right(NULL){};
};
class Tree{
    Node *root;
public:
    Tree():root(NULL){};
    Node* makeTree(string m[], int from, int n);
    void TreeOut(Node *root);
    void printBT(const string& prefix, const Node* node, bool isLeft);
    void levelOrder(Node* root, string m[], int from);
};

#endif /* Tree_hpp */
