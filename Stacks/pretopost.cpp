#include<bits/stdc++.h>
using namespace std;
void pretopost(string s){
    stack<string> st;
    int i = 0;
    reverse(s.begin(), s.end());
    while(s[i]){
        string ch=string(1, s[i]);  //you can use this or at the time pushing operand use st.push(to_string(s[i]-'0'))      
        if(isdigit(s[i])){
            st.push(ch);
        }
        else{
            if (st.size() < 2) {//to check invalid expressions
                cout<<"Invalid prefix expression";
                return;
            }
            string v1 = st.top();
            st.pop();
            string v2 = st.top();
            st.pop();
            string result =  v1 + v2 + ch;
            st.push(result);
        }
        i++;
    }
    if (st.size()!= 1) {//to check invalid expressions
        cout<<"Invalid prefix expression";
        return;
    }
    cout << "the postfix expression is: " << st.top();
}
int main(){
    string s;
    cout << "enter the prefix expression: ";
    cin >> s;
    pretopost(s);
}