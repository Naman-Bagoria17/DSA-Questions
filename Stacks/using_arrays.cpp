#include<bits/stdc++.h>
using namespace std;
class Stack{
    int capacity;
    int *arr;
    int top;
    public:
    //All below functions are of O(1) 
    Stack(int c){
        this->capacity = c;
        arr = new int[c];
        this->top = -1;
    }
    void push(int data){
        if(this->top==this->capacity-1){
            cout << "Overflow!!\n";
            return;
        }
        this->top++;
        this->arr[this->top] = data;
    }
    int pop(){//void bhi rakh sakte hai if you dont want to return anything 
        if(this->top==-1){
            cout << "UNDERFLOW!!\n";
            return INT_MIN;
        }
        int result = this->top;
        this->top--;//bas uska access hathana hai, usko delete krne ke liye koi fight ni krni
        return result;
    }
    int get_top(){
        if(this->top==-1){
            cout << "UNDERFLOW!!\n";
            return INT_MIN;
        }
        return this->arr[this->top];
    }
    bool isEmpty(){
        return this->top == -1;
    }
    int size(){
        return this->top + 1;
    }
    bool  isFull(){
        return this->top == this->capacity - 1;
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
    cout << s.isFull()<<endl;
    s.push(6);
    s.pop();
    s.pop();
    s.pop();
    cout<<s.isEmpty()<<endl;
    s.pop();
    s.pop();
    cout<<s.isEmpty()<<endl;
    s.pop();
}