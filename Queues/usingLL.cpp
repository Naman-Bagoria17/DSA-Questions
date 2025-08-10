#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        next = nullptr;
    }
};
//All operations are O(1)
class Queue{
    Node *head;
    Node *tail;
    int capacity;
    int curr_size;
    public:
    Queue(int c){
        head = nullptr;
        tail = nullptr;
        capacity = c;
        curr_size = 0;
    }
    void enqueue(int value){
        Node *new_node = new Node(value);
        if(this->curr_size==this->capacity){
            cout << "OVERFLOW!!" << endl;
            return;
        }
        if(this->head==nullptr){
            this->head = this->tail = new_node;
        }
        else{
            this->tail->next = new_node;
            this->tail = new_node;
        }
        this->curr_size++;
    }
    void dequeue(){
        if(head==nullptr){
            cout << "UNDERFLOW!!" << endl;
            return;
        }
        else{
            Node *del_node = this->head;
            this->head = this->head->next;
            if(this->head==nullptr)
                this->tail = nullptr;
            del_node->next = nullptr;
            delete (del_node);
        }
        this->curr_size--;
    }
    bool isFull(){
        return this->curr_size == capacity;
    }
    bool isEmpty(){
        return head==nullptr;
    }
    int front(){
        if(this->head==nullptr){
            return -1;
        }
        else{
            return this->head->data;
        }
    }
};
int main(){
    Queue qu(5);
    qu.enqueue(1);
    qu.enqueue(2);
    qu.enqueue(3);
    qu.enqueue(4);
    qu.enqueue(5);
    qu.enqueue(7);//overflow
    while(!qu.isEmpty()){
        cout << qu.front() << endl;
        qu.dequeue();
    }
    cout << qu.front() << endl;//-1
    qu.dequeue();//underflow
}