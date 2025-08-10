// #include<bits/stdc++.h>
// using namespace std;
// // below code is of O(1) TC and O(n) SC
// class MinStack{
//     stack<int> s;
//     stack<int> temp;
// public:
//     MinStack(){

//     }
//     void push(int data){
//        s.push(data);
//        if(temp.empty() || data<=temp.top()){
//            temp.push(data);
//        }
//     }
//     void pop(){
//         if(temp.top()==s.top())
//             temp.pop();
//         s.pop();
//     }
//     int get_top(){
//         return s.top();
//     }
//     int getMin(){//in O(1)
//         return temp.top();
//     }
// };
// int main(){
//     MinStack s;
//     s.push(16);
//     s.push(18);
//     s.push(14);
//     s.push(25);
//     s.push(12);
//     cout << s.getMin()<<endl;
//     s.pop();
//     s.pop();
//     cout << s.getMin()<<endl;
//     s.push(9);
//     cout << s.getMin()<<endl;
// }

//below is of O(1) for both TC and SC
class MinStack{
    stack<int> s;
    int min = INT_MAX;
public:
    MinStack(){
    }
    void push(int data){
        if(this->s.empty()){
            this->min = data;
            this->s.push(data);
        }
        else{
            this->s.push(data - this->min);
            if(data<this->min){
                this->min = data;
            }
        }
    }
    void pop(){
        if(not this->s.empty()){
            if(this->s.top()>=0){
                this->s.pop();
            }
            else{
                this->min -= this->s.top();
                this->s.pop();
            }
        }
        else{
            this->min = INT_MAX;
            cout << "UNDERFLOW!!" << endl;
        }
    }
    int get_top(){
        if(this->s.size()==1)
            return this->s.top();
        else{
            if(this->s.top()<0)
                return this->min;
            else{
                return this->min + this->s.top();
            }
        } 
    }
    int getMin(){
        return this->min;
    }
};
int main(){
    MinStack s;
    cout << s.getMin() << endl;
    s.push(16);
    cout << s.getMin() << endl;
    s.push(18);
    cout << s.getMin() << endl;
    s.push(-14);
    s.push(25);
    s.push(-15);
    cout << s.getMin()<<endl;
    s.pop();
    cout << s.getMin()<<endl;
    s.push(-18);
    cout << s.getMin()<<endl;
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    cout << s.getMin()<<endl;
}