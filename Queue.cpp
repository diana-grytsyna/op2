//
//  Queue.cpp
//  lab26
//
//  Created by Діана on 23.05.2022.
//

#include "Queue.hpp"
int Queue::isEmpty(){
    if(Head == NULL)
        return 1;
    else
        return 0;
}
void Queue::addToQueue(Node *tmp){
    QueueNode *Ptr = new QueueNode;
    Ptr -> trans = tmp;
    if(Head == NULL){
        Head = Ptr;
        Ptr -> next = NULL;
    }else{
        QueueNode *tmp_c = Head;
        while(tmp_c -> next != NULL)
            tmp_c = tmp_c -> next;
        tmp_c -> next = Ptr; //наступний рівень
        Ptr -> next = NULL;
    }
}
Node* Queue::delQueue(){
    QueueNode *cur = Head -> next;
    Node *tmp_c = Head -> trans;
    if(Head != NULL){
        delete Head;
        Head = cur;//заміна на наступну вершину
        return tmp_c;
    }
    else
        return NULL;
}
