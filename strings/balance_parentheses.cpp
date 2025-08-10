#include<bits/stdc++.h>
using namespace std;
bool check_balance(string p,int count){
    int i = 0;
    while(p[i]){
        if(p[i]=='(')
            count++;
        if(p[i]==')'){
            if(count>0)//to see that is closing ke liye koi pehle opening aaya bhi tha ya nahi
                count--;
            else
                return false;
        }
        i++;
    }
    if (count==0)
        return true;
    else
        return false;
}
int main(){
    string p;
    cout << "enter the string: ";
    cin >> p;
    cout << check_balance(p, 0);
}