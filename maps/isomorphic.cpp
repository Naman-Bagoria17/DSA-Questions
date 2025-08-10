//Two strings are isomorphic of each other if there is 
//one to one mapping possible for every character of the first string to every 
//character of second string and all occurrences of every
//character in the first string maps to same character in the second string

#include<bits/stdc++.h>
using namespace std;
bool check_mapping(string s1,string s2){
    unordered_map<char, char> m;
    for (int i = 0; i < s1.size();i++){
        if(m.find(s1[i])==m.end()){
            m[s1[i]] = s2[i];
        }
        else{
            if(m[s1[i]]!=s2[i]){
                return false;
            }
        }
    }
    return true;
}
bool check_isomorphic(string s1,string s2){
    if(s1.size()!=s2.size()){
        return false;
    }
    bool s1s2 = check_mapping(s1, s2);
    bool s2s1 = check_mapping(s2, s1);

    return s1s2 && s2s1;
}
int main(){
    string s1, s2;
    cout << "Enter two strings: ";
    cin >> s1 >> s2;
    cout << (check_isomorphic(s1, s2) ? "Isomorphic!!" : "Not Isomorphic!!") << endl;

    //TC-O(N), N->sum of length of s1 and s2
    //SC-O(M), M->unique characters in larger string
}