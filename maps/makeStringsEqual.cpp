//Can you make all strings in array equal
// by moving any number of characters any number of times 
//from one string to any other

#include<bits/stdc++.h>
using namespace std;
//Logic- each and every character must be present in all the strings of the array equal number of times
//so make frequency map for every character
//and each character must be present in multiple of length of array
int main(){
    vector<string> str;
    int n;
    cout << "Enter n: ";
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        str.push_back(s);
    }
    unordered_map<char,int> freq;
    for (auto ele : str)
    {
        for (auto ch : ele)
        {
            freq[ch]++;
        }
    }
    bool flag = true;
    for (auto pair : freq){
        if(pair.second%str.size()!=0){
            flag = false;
            break;
        }
    }
    if(flag==true)
        cout << "Strings can be made equal!!";
    else
        cout << "Strings can't be made equal!!";

    //TC-O(n),n->number of total characters in all the strings
    //SC-O(m),m->number of unique characters in all the strings
}