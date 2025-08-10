#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<int> s,p;
    s.push(1);
    s.push(2);
    p.push(3);
    p.push(4);
    s.swap(p);
    cout << s.top() << endl;
    cout << p.top();
}