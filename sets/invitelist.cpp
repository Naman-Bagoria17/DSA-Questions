#include<bits/stdc++.h>
using namespace std;
int main(){
    set<string> inviteList;
    int n;
    cout << "Enter the number of names: ";
    cin >> n;
    cout << "Enter the names :";
    while(n--){
        string name;
        cin >> name;
        inviteList.insert(name);
    }
    cout << "Invite list: " << endl; 
    for(auto name: inviteList){
        cout << name << endl;
    }
}