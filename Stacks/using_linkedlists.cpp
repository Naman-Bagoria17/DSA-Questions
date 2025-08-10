#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
    Node(int val){//here argument name cannot be data because then data will have a garbage value
        this->data = val;
        this->next = nullptr;
    }
};
class Stack{
    Node *head;
    int capacity;
    int curr_size;
    public:
    Stack(int c){
        this->capacity = c;
        this->head = nullptr;
        this->curr_size = 0;
    }
    bool isempty(){
        return this->head == nullptr;
    }
    bool isfull(){
        return this->curr_size == this->capacity;
    }
    void push(int val){
        if(this->curr_size==this->capacity){
            cout << "OVERFLOW!!\n";
            return;
        }
        Node *new_node = new Node(val);
        new_node->next = this->head;
        this->head = new_node;
        this->curr_size++;
    }
    int pop(){
        if(head==nullptr){
            cout << "UNDERFLOW!!\n";
            return INT_MIN;
        }
        Node *del_node = this->head;
        int result = del_node->data;
        this->head = this->head->next;
        del_node->next = nullptr;
        delete del_node;
        this->curr_size--;
        return result;
    }
    int size(){
        return this->curr_size;
    }
    int get_top(){
        if(this->head==nullptr){
            cout << "UNDERFLOW!!\n";
            return INT_MIN;
        }
        return this->head->data;
    }
};
int main(){
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.get_top() << endl;
    s.pop();
    cout << s.get_top() << endl;
    s.push(3);
    s.push(4);
    s.push(5);
    cout << s.isfull()<<endl;
    s.push(6);
    s.pop();
    s.pop();
    s.pop();
    cout<<s.isempty()<<endl;
    s.pop();
    s.pop();
    cout<<s.isempty()<<endl;
    s.pop();
}