                                            
                                            //push-efficient 

// #include<bits/stdc++.h>
// using namespace std;
// class Queue{
//     stack<int> st;
//     public:
//     //default constructor will be made by compiler
//     void push(int ele){//enqueue O(1)
//         this->st.push(ele);
//     }
//     void pop()
//     { // O(n), n->size of queue
//         if(this->st.empty())
//             return;
//         if(this->st.size()==1){
//             st.pop();
//             return;
//         }
//         int curr = this->st.top();
//         this->st.pop();
//         pop();
//         this->st.push(curr);
//     }
//     bool empty(){//O(1)
//         return this->st.empty();
//     }
//     int front(){//O(n)
//         if(this->st.empty())
//             return -1;
//         stack<int> temp;
//         while(this->st.size()>1){
//             temp.push(this->st.top());
//             this->st.pop();
//         }
//         int res = this->st.top();
//         while(not temp.empty()){
//             this->st.push(temp.top());
//             temp.pop();
//         }
//         return res;
//     }
// };
// int main(){
//     Queue qu;
//     qu.push(10);
//     qu.push(20);
//     qu.push(30);
//     qu.push(40);
//     qu.pop();
//     while(not qu.empty()){
//         cout << qu.front() << " ";
//         qu.pop();
//     }
//     return 0;
// }

//                                             //pop efficient

#include<bits/stdc++.h>
using namespace std;
class Queue{
    stack<int> st;
    public:
    //default constructor will be made by compiler
    void push(int ele){//enqueue O(n), n->size of queue
        if(this->st.empty()){
            st.push(ele);
            return;
        }
        int curr = this->st.top();
        this->st.pop();
        push(ele);
        this->st.push(curr);        
    }
    void pop()
    { // O(1)
        if(this->st.empty()){
            cout<<"Underflow!!"<<endl;
            return;
        }
        this->st.pop();
    }
    bool empty(){//O(1)
        return this->st.empty();
    }
    int front(){//O(1)
        if(this->st.empty())
            return -1;
        return this->st.top();
    }
};
int main(){
    Queue qu;
    qu.push(10);
    qu.push(20);
    qu.push(30);
    qu.push(40);
    qu.pop();
    while(not qu.empty()){
        cout << qu.front() << " ";
        qu.pop();
    }
    return 0;
}