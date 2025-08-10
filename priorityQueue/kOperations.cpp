#include<bits/stdc++.h>
using namespace std;
//overall TC-O(nlogn)
int k_operations(vector<int> v,int k){
    int ans = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(auto& ele:v){//nlogn
        pq.push(ele);
    }
    while(k--){//klogn-removing and inserting k elements
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        int prod = first * second;
        pq.push(prod);
    }
    while(pq.size()>1){//(n-k)logn
        pq.pop();
    }
    return pq.top();
}
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto&ele:v){
        cin >> ele;
    }
    cout << k_operations(v, k);
    return 0;
}