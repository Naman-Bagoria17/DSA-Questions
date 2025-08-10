#include<bits/stdc++.h>
using namespace std;
//equal_range(key)-when we want all the pairs with a particular key then we use this
//it returns a pair that contains a start itr and a end itr
//start itr->itr to first pair in the map with the passed key
//and a end iterator->itr to the pair after the last pair in the map with the passed key
int main(){
    multimap<int, int> record;
    record.insert({1,1});
    record.insert(make_pair(2, 4));
    record.insert(make_pair(3, 9));
    record.insert(make_pair(4, 16));
    record.insert(make_pair(4, 20));
    record.insert(make_pair(4, 24));
    record.insert(make_pair(5, 32));
    auto p = record.equal_range(4);//returns a pair
    for (auto itr = p.first;itr!=p.second;itr++){//itr is initially pointing to the first pair with the key 4
        cout << itr->first << " " << itr->second << endl;
    }
}