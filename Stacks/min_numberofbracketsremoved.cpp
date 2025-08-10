#include<bits/stdc++.h>
using namespace std;
int is_balance(string p){
    stack<char> s;
    int i = 0;
    int count;
    while(p[i]){
        if(p[i]=='{' || p[i]=='(' || p[i]=='['){
            s.push(p[i]);
        }
        else{
            if(p[i]==')' && !s.empty() && s.top()=='('){
                s.pop();
            }
            else if(p[i]==']' && !s.empty() && s.top()=='['){
                s.pop();
            }
            else if(p[i]=='}' && !s.empty() && s.top()=='{'){
                s.pop();
            }
            else
            // ya pe aana ka mtlb hai opening brackett se pehle closing brackett aagya  
            // ya fir aur koi opening brackett ke corresponding dusra closing brackett mila hai
            {
                count++;
            }
        }
        i++;
    }
    return count+s.size();//s.size() to  check if there may be opening bracketts waiting in the stack to get their closing bracketts
}
int main(){
    string str;
    cout << "enter the brackett string: ";
    cin >> str;
    cout << is_balance(str);
}