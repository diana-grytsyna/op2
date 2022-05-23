//
//  Queue.hpp
//  lab26
//
//  Created by Діана on 23.05.2022.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>
#include "Tree.hpp"
struct QueueNode{
    Node *trans;
    QueueNode *next;
};
class Queue{
    QueueNode *Head;
 public:
        Queue(){Head = NULL;}
        int isEmpty();
        void addToQueue(Node *tmp);
        Node *delQueue();
};
#endif /* Queue_hpp */
