//
//  Tree.cpp
//  lab26
//
//  Created by Діана on 16.05.2022.
//

#include "Tree.hpp"
#include "Queue.hpp"
#include <iostream>
using namespace std;
Node* Tree::makeTree(string m[], int from, int n){
    if(n==0)return NULL;
    Node* p = new Node(m[from]);
    int nl = n/2;
    int nr = n-nl-1;
    p->left = makeTree(m, from+1, nl);
    p->right = makeTree(m, from+nl+1, nr);
    return p;
}
void Tree::TreeOut(Node *root){
    Node* current = root;
    int stop = 0;
    while(stop==0){
        while(current!=NULL){
            cout<<current->data<<endl;
            current = current->left;
        }
        if(current==NULL) stop = 1;
        else {
            cout<<current->data<<endl;
            current = current->right;
            
        }
    }
}
void Tree::printBT(const string& prefix, const Node* node, bool isLeft){
    if( node != nullptr ){
        cout<<prefix;
        cout<<(isLeft ? "├──" : "└──" );
        cout<<node->data<<endl;
        printBT(prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT(prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}
void Tree::levelOrder(Node* root, string m[], int from){
    Queue Universal;
    Universal.addToQueue(root);
    Node *tmp;
    while(!Universal.isEmpty()){
        tmp = Universal.delQueue();
        tmp->data = m[from];//заміна значення data у вершині
        from++;
            //перевірка наявності піддерев
                if(tmp -> left != NULL)
                    Universal.addToQueue(tmp -> left);
                if(tmp -> right != NULL)
                    Universal.addToQueue(tmp -> right);
            }
}
 
