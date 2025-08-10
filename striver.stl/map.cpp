#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_map<char,int> freq;
    string s="aabcdedab";
    for(char c:s){
        freq[c]++;
    }
    cout<<"character"<<setw(20)<<"frequency"<<endl<<endl;
    for(auto &pair:freq){
        cout<<pair.first<<setw(20)<<pair.second<<endl;
    }
}