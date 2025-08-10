//check if the given string has all the english alphabets or not
//Note: every alphabet can be in lower case or uppercase
#include<bits/stdc++.h>
using namespace std;
int main(){
    set<int> st;
    string s;
    cout << "enter the string: ";
    cin >> s;
    if(s.size()<26){
        cout << "No" << endl;
        exit(0);
    }
    transform(s.begin(), s.end(), s.begin(), ::tolower);//converting all to lowercase
    for(int i = 0; i < s.size();i++){//inserting the characters into set
        st.insert(s[i]);
    }
    if(s.size()==26){
        cout << "Yes!!" << endl;
    }
    else{
        cout << "No!!" << endl;
    }
}