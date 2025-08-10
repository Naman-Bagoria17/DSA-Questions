#include<bits/stdc++.h>
using namespace std;
//considering 0 based indexing from bottom
void insertAtIndex(stack<int> &s, int val,int idx)
{   //if(idx>=s.size()){
    //  cout << "Invalid Index!!" << endl;
    //  exit(0);
    // }
    if(s.size()==idx){
        s.push(val);
        return;
    }
    int curr = s.top();
    s.pop();
    insertAtIndex(s, val, idx);
    s.push(curr);
}
int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    //s-> 5 4 3 2 1
    int idx, val;
    cout << "Enter the value to be inserted: ";
    cin >> val;
    cout << "Enter the index where it needs to be inserted: ";
    cin >> idx;
    insertAtIndex(s, val, idx);
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
}