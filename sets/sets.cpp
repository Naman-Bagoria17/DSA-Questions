#include<bits/stdc++.h>
using namespace std;
int main(){
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    cout << s.size() << endl;
    s.insert(2);//duplicate element not added to the set
    cout << s.size() << endl;

    //TRAVERSAL
    set<int>::iterator it;
    for (it = s.begin(); it != s.end();it++){
        cout << *it << " ";
    }
    cout << endl;
    for(auto ele:s){
        cout << ele << " ";
    }
    cout << endl;
    s.insert(5);
    s.insert(6);
    s.insert(7);

    //DELETION
    s.erase(4);//deleting 4 through its value
    for(auto ele:s){
        cout << ele << " ";
    }
    cout << endl;
    s.insert(4);
    auto itr = s.begin();
    advance(itr, 3);//now itr pointing to 4
    s.erase(itr); // deleting 4 through its position
    for(auto ele:s){
        cout << ele << " ";
    }
    cout << endl;
    s.insert(4);
    auto itr1 = s.begin();
    auto itr2 = s.begin();
    advance(itr2, 3);//itr2 pointing to 4
    s.erase(itr1, itr2); // deleting from value 1 to 3
    for(auto ele:s){
        cout << ele << " ";
    }
}
