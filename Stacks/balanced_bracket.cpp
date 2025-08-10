#include<bits/stdc++.h>
using namespace std;
bool is_balance(string p){
    stack<char> s;
    int i = 0;
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
            {    return false;
            }
        }
        i++;
    }
    return s.empty();//stack me koi opening brackett wait to ni kr raha 
}
int main(){
    string str;
    cout << "enter the brackett string: ";
    cin >> str;
    cout << is_balance(str);
}