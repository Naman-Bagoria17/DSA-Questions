#include<bits/stdc++.h>
using namespace std;
//Here there is a wastage of space when you remove elements with O(1) time complexity
class Queue{
    int front;
    int rear;
    int capacity;
    int curr_size;
    vector<int> v;
    public:
    Queue(int c){
        front = -1;
        rear = -1;
        capacity = c;
        curr_size = 0;
    }
    void enqueue(int data){
        if(this->curr_size==this->capacity){
            cout << "Overflow!!" << endl;
            return;
        }
        if(this->curr_size==0){
            //you are adding first element
            this->front++;
        }
        v.push_back(data);
        this->rear++;
        this->curr_size++;
    }
    void dequeue(){
        if(this->curr_size==0){
            cout << "Underflow!!" << endl;
            return;
        }
        if(this->front==this->rear){//if queue had only one element
            this->front = -1;
            this->rear = -1;
            this->v.clear();
        }
        else
            this->front++;
        this->curr_size--;
    }
    bool isEmpty(){
        return this->front == -1;
    }
    bool isFull(){
        return this->capacity == this->curr_size;
    }
    int get_front(){
       if(this->front==-1)return -1;
       return this->v[front];
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
        cout << qu.get_front() << endl;
        qu.dequeue();
    }
    cout << qu.get_front() << endl;//-1
    qu.dequeue();//underflow
}