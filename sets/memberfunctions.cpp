#include<bits/stdc++.h>
using namespace std;
int main(){
    set<int> s;

    cout << s.empty() << endl; // returns true

    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(6);

    cout << s.size() << endl;// returns 5

    cout << s.max_size() << endl;//returns maximum number of elements set can hold
    // As memory is allocated dynamically to set
    //so whenever our size of set reaches near to max_size, max_size increases automatically

    s.clear();//clears the set(removes all elements)
    cout << s.size() << endl;

    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(6);

    //find()-returns iterator to the element if present, otherwise returns end iterator
    //searching:-O(log n)
    if(s.find(8)!=s.end()){
        cout << "value is present!!" << endl;
    }
    else{
        cout << "value is not present!!" << endl;
    }

    cout << s.count(4) << endl;//return number of occurrences of element in the set

    //lower_bound()-return the iterator to the element if present otherwise iterator to just greater value
    //if all the values are less than given value then it returns end iterator
    //O(logn)
    cout << *s.lower_bound(5)<<endl;
    cout << *s.lower_bound(4)<<endl;
    cout << *s.lower_bound(10)<<endl;//can give any random value

    //lower_bound()-return the iterator  just greater value
    //if all the values are less than given value then it returns end iterator
    //O(logn)
    cout << *s.upper_bound(5)<<endl;
    cout << *s.upper_bound(4)<<endl;    
    cout << *s.upper_bound(10)<<endl;    
}