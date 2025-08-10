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
int precdence(char ch){
    if(ch=='^')
        return 3;
    if(ch=='*' || ch=='/')
        return 2;
    if(ch=='+' || ch=='-'){
        return 1;
    }
    else
        return -1;
}
int evaluate(string s){
    stack<char> optr;
    stack<int> opnd;
    int i = 0;
    while(s[i]){
       if(isdigit(s[i])){
           int num = 0;
           while (i < s.size() && isdigit(s[i]))
           {
               num = num * 10 + (s[i] - '0');
               i++;
            }
            opnd.push(num);
            continue;
       }
        if(s[i]=='('){
            optr.push(s[i]);
        }
        else if(s[i]==')'){
            while(not optr.empty() && optr.top()!='('){
                char op = optr.top();
                optr.pop();
                int v1 = opnd.top();
                opnd.pop();
                int v2 = opnd.top();
                opnd.pop();
                int result = operate(v2, v1, op);
                opnd.push(result);
            }
            optr.pop();//to remove opening brackett
        }
        else{
            //agr operator aa raha hai aur km precedence ka hai 
           while(!optr.empty() && (precdence(s[i]) < precdence(optr.top()) || 
       (precdence(s[i]) == precdence(optr.top()) && s[i] != '^'))) {//bcz ^ has associativity right to left
                //pehle evaluate krlo
                char op = optr.top();
                optr.pop();
                int v1 = opnd.top();
                opnd.pop();
                int v2 = opnd.top();
                opnd.pop();
                int result = operate(v2, v1, op);
                opnd.push(result);
            }
            //agr zyada precedence hai
            optr.push(s[i]);
        }
        i++;
    }
    //it is possible abhi dono stack me humara kaam krne vala pada hai 
    while(not optr.empty()){
        char op = optr.top();
        optr.pop();
        int v1 = opnd.top();
        opnd.pop();
        int v2 = opnd.top();
        opnd.pop();
        int result = operate(v2, v1,op);
        opnd.push(result);
    }
    return opnd.top();
}
int main(){
    string s;
    cout << "enter the infix expression: ";
    cin >> s;
    cout << "the result is: " << evaluate(s);
}