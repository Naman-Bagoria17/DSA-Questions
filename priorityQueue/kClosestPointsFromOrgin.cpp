#include<bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
vector<pp> kClosestPoints(vector<pp> v,int k){
    vector<pp> ans(k);
    priority_queue<pair<int, pp>> pq;
    for(auto&pt:v){
        int dist = abs(pt.first) + abs(pt.second);
        pq.push({dist, pt});
        if(pq.size()>k){
            pq.pop();
        }
    }
    while(!pq.empty()){
        ans[pq.size()-1]=pq.top().second;
        pq.pop();  
    }
    return ans;
}
int main(){
    int n, k;
    cin >> n >> k;
    vector<pp> v(n);
    for(auto&pt:v){
        cin >> pt.first >> pt.second;
    }
    vector<pp> ansPts(k);
    ansPts = kClosestPoints(v,k);
    for(auto&pt:ansPts){
        cout << pt.first << " " << pt.second << endl;
    }
    return 0;
}