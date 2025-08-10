#include<bits/stdc++.h>
using namespace std;
// space and time complexity-O(n) if we use two temporary stacks
// here using recursion TC is O(n^2) and S.C is O(n).
void insert_bottom(stack<int> &s,int val){
    if(s.empty()){
        s.push(val);
        return;
    }
    int curr = s.top();
    s.pop();
    insert_bottom(s, val);
    s.push(curr);
}
void reverse(stack<int> &s){
    if(s.empty()){
        return;
    }
    int curr = s.top();
    s.pop();
    reverse(s);
    insert_bottom(s, curr);//cannot use s.top() here because there is nothing in s. everything is in call stack
}
int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    //s-> 4 3 2 1
    reverse(s);
    while(!s.empty()){
        cout << s.top() << endl ;
        s.pop();
    }
}