#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node *previous;
    Node(int data){
        this->data = data;
        next = nullptr;
        previous = nullptr;
    }
};
class Deque{
    Node *head;
    Node *tail;
    int capacity;
    int curr_size;
    public:
    Deque(int c){
        head = nullptr;
        tail = nullptr;
        capacity = c;
        curr_size = 0;
    }
    void push_front(int data){
        if(this->curr_size==this->capacity){
            cout << "Overflow!!" << endl;
            return;
        }
        Node *new_node = new Node(data);
        if(this->curr_size==0){
            this->head=this->tail = new_node;
        }
        else{
            new_node->next = this->head;
            this->head->previous = new_node;
            this->head = new_node;
        }
        this->curr_size++;
    }
    void push_back(int data){
        if(this->curr_size==this->capacity){
            cout << "Overflow!!" << endl;
            return;
        }
        Node *new_node = new Node(data);
        if(this->curr_size==0){
            this->head=this->tail = new_node;
        }
        else{
            this->tail->next = new_node;
            new_node->previous = this->tail;
            this->tail = new_node;
        }
        this->curr_size++;
    }
    void pop_front(){
        if(this->curr_size==0){
            cout << "Underflow!!" << endl;
            return;
        }
        Node *del_node = this->head;
        this->head = this->head->next;
        del_node->next = nullptr;
        delete (del_node);
        if(this->head==nullptr){
            this->tail = nullptr;
        }
        else{
            this->head->previous = nullptr;
        }
        this->curr_size--;
    }
    void pop_back(){
        if(this->curr_size==0){
            cout << "Underflow!!" << endl;
            return;
        }
        Node *del_node = this->tail;
        this->tail = this->tail->previous;
        del_node->next = nullptr;
        delete (del_node);
        if(this->tail==nullptr){
            this->head = nullptr;
        }
        else{
            this->tail->next = nullptr;
        }
        this->curr_size--;
    }
    bool isEmpty(){
        return this->curr_size == 0;
    }
    bool isFull(){
        return this->curr_size == this->capacity;
    }
    int front(){
        if(this->curr_size==0){
            return -1;
        }
        else{
            return this->head->data;
        }
    }
    int back(){
        if(this->curr_size==0){
            return -1;
        }
        else{
            return this->tail->data;
        }
    }
};
int main(){
    Deque dq(5);
    cout<<dq.isEmpty()<<endl;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_front(4);
    dq.push_front(5);
    dq.pop_back();
    dq.pop_front();
    while(!dq.isEmpty()){
        cout << dq.front()<<" ";
        dq.pop_front();
    }
    cout << endl;
}