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
    int i = 0;
    while(s[i]){
        if(isdigit(s[i])){
            st.push(s[i] - '0');
        }
        else{
            int v1 = st.top();
            st.pop();
            int v2 = st.top();
            st.pop();
            int result = operate(v2, v1, s[i]);//because v2 vo hai jo niche pada tha mtlb string me pehle aa rha hai
            st.push(result);
        }
        i++;
    }
    return st.top();
}
int main(){
    string s;
    cout << "enter the postfix expression: ";
    cin >> s;
    cout << "the result is: " << evaluate(s);
}