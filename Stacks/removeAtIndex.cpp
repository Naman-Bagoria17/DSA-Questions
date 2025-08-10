#include<bits/stdc++.h>
using namespace std;
//considering 0 based indexing from bottom
void remove_at_index(stack<int> &s,int idx)
{
    if(idx==s.size()-1){
        s.pop();
        return;
    }
    int curr = s.top();
    s.pop();
    remove_at_index(s, idx);
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
    int idx;
    cout << "Enter the index from which value needs to be removed: ";
    cin >> idx;
    remove_at_index(s, idx);
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
}