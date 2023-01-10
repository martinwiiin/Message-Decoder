#ifndef PRIOQUEUE_H
#define PRIOQUEUE_H
#include <iostream>
using namespace std;

struct node{
    string data;
    int prio;
    node* next;
};


class prioQueue{
    private:
        node* head;
        node* tail;  
    public:
        prioQueue();
        void dequeue();
        void enqueue(string data, int prio);
        bool isEmpty();
        void print();
        node* getHead();
};

prioQueue::prioQueue(){
    head = nullptr;
    tail = nullptr;
}

bool prioQueue::isEmpty(){
    return (head == nullptr);
}

node* prioQueue::getHead(){
    if(!isEmpty()){
        return head;
    }
    else{
        return nullptr;
    }
    
}

void prioQueue::enqueue(string data, int prio){
    //cout << "Enqueueing " << endl;
    node* temp = new node();
    temp->data = data;
    temp->prio = prio;
    temp->next = nullptr;
    if(isEmpty()){
        head = temp;
        tail = temp;
    }
    else{
        node* cu = head;
        node* prev = nullptr;
        if(temp->prio < cu->prio){
            temp->next = head;
            head = temp;
        }
        else{
            while(cu != nullptr && temp->prio >= cu->prio){
                prev = cu;
                cu = cu->next;
            }
            prev->next = temp;
            temp->next = cu;
            if(temp->next == nullptr){
                tail = temp;
            }
        }
    }
}



void prioQueue::print(){
    node* cu = head;
    while(cu != nullptr){
        cout << cu->data << endl;
        cu = cu->next;
    }
}

void prioQueue::dequeue(){
    if(isEmpty()){
        cout << "Queue is empty" << endl;
    }
    else{
        node* temp = head;
        head = head->next;
        delete temp;
    }
}



#endif