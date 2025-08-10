#include<bits/stdc++.h>
//here no need to include <stack> header file
using namespace std;
int main(){
    stack<int> s;
    cout << s.empty() << endl;
    cout << s.top();//no output or segmentation fault
    s.pop();//no output or segmentation fault
    s.push(1);
    s.push(2);
    s.emplace(3);
    cout<<s.top()<<endl;
    s.pop();
    cout << s.top() << endl;
    s.push(4);
    s.push(5);
    cout << s.empty() << endl;
    return 0;
}