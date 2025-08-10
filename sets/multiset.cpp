#include<bits/stdc++.h>
using namespace std;
int main(){
    multiset<int,greater<int>> ms;//in descending order
    ms.insert(1);
    ms.insert(2);
    ms.insert(1);
    ms.insert(3);
    for(auto ele:ms){
        cout << ele << " ";
    }
    cout << endl;
}
