#include<bits/stdc++.h>
using namespace std;
//using stack
void rev_using_st(queue<int> &q){
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

//using recursion
void rev_using_rec(queue<int> &q){
    if(q.size()==1){
        return;
    }
    int curr = q.front();
    q.pop();
    rev_using_rec(q);
    q.push(curr);
}
int main(){
    queue<int> qu;
    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(4);
    rev_using_rec(qu);
    while(!qu.empty()){
        cout << qu.front()<<" ";
        qu.pop();
    }
}