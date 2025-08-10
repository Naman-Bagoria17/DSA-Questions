#include<bits/stdc++.h>
using namespace std;
int operate(int  v1,int v2,char op){
    if(op=='^'){
        return pow(v1, v2);
    }
    if(op=='*'){
        return v1*v2;
    }
    if(op=='/'){
        return v1/v2;
    }
    if(op=='+'){
        return v1+v2;
    }
    else{
        return v1 - v2;
    }
}
int evaluate(string s){
    stack<int> st;
    int i = s.size()-1;
    while(s[i]){
        if(isdigit(s[i])){
            st.push(s[i] - '0');
        }
        else{
            int v1 = st.top();
            st.pop();
            int v2 = st.top();
            st.pop();
            int result = operate(v1, v2, s[i]);
            st.push(result);
        }
        i--;
    }
    return st.top();
}
int main(){
    string s;
    cout << "enter the prefix expression: ";
    cin >> s;
    cout << "the result is: " << evaluate(s);
}