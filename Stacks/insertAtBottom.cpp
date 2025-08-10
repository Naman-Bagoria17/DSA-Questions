#include<bits/stdc++.h>
using namespace std;
//space-O(n) and time complexity-O(n^2)
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
int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    //s-> 4 3 2 1
    insert_bottom(s, 7);
    while(!s.empty()){
        cout << s.top() << endl ;
        s.pop();
    }
}