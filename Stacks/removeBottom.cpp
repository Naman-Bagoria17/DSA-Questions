#include<bits/stdc++.h>
using namespace std;
void remove_bottom(stack<int> &s){
    if(s.size()==1){
        s.pop();
        return;
    }
    int curr = s.top();
    s.pop();
    remove_bottom(s);
    s.push(curr);
}
int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    //s-> 4 3 2 1
    remove_bottom(s);
    while(!s.empty()){
        cout << s.top() << endl ;
        s.pop();
    }
}