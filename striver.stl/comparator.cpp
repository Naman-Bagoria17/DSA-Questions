#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> p1, pair<int,int> p2){//just pass two pairs
    if(p1.second<p2.second) return true;
    if(p1.second>p2.second) return false;
    if(p1.first>p2.first)return true;
    return false;

}
int main(){
    pair<int,int> a[]={{1,2},{2,1},{4,1}};
    //imagine if you want to sort in the order like:
    // sort according to first element 
    //if second element is same
    //sort according to first element but in descending
    //here comes user built comparator
    sort(a,a+3,comp);
    for(const auto& pair:a){
        cout<<pair.first<<" "<<pair.second<<endl;
    }
}