#include<bits/stdc++.h>
using namespace std;
int main(){
    set<int> s;
    int n;
    cout << "Enter n: ";
    cin >> n;
    while(n--){
        int num;
        cin >> num;
        s.insert(num);
    }
    if(s.size()==1){//means there is no second smallest element
        cout << -1;
    }
    else{
        auto itr = s.begin();
        itr++;
        cout << *itr;
    }
}