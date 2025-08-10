#include<bits/stdc++.h>
using namespace std;
//TC- O(nlogk) traversing n elements but priority queue has only k elements
int kthLargest(vector<int> v,int k){
    int n = v.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    int i = 0;
    while(i<n){
        pq.push(v[i]);
        if(pq.size()>k){
            pq.pop();
        }
        i++;
    }
    return pq.top();
} 
int main()
{
    vector<int> v = {1, 5, 2, 11, 9};
    cout << kthLargest(v, 1);
}