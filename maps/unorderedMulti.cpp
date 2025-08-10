#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_multimap<string, int> record;
    record.insert(make_pair("Naman", 12));
    record.insert(make_pair("Naman", 9));
    //Same keys will be together always
    record.insert(make_pair("Jatin", 35));
    record.insert(make_pair("Hitesh", 13));
    record.insert(make_pair("Naman", 13));
    record.insert(make_pair("Jayant", 54));
    for(auto pair:record){
        cout << pair.first << setw(20) << pair.second << endl;
    }
}