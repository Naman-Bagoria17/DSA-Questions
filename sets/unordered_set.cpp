#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_set<int> us;
    us.insert(1);
    us.insert(2);
    us.insert(1);
    us.insert(3);
    for(auto ele:us){
        cout << ele << " ";
    }
    cout << endl;
}