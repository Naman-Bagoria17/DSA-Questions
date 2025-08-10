#include<bits/stdc++.h>
using namespace std;
bool canPlaceKids(vector<int>& v,int mid,int s){
    int kidsReq = 1;
    int lastPlaced = v[0];
    for (int i = 0; i < v.size();i++){
        if(v[i]-lastPlaced>=mid){//means adjacent kids ke beech at least min distance to hai
            kidsReq++;
            if(kidsReq==s)
            { // all kids placed
                return true;
            }
            lastPlaced = v[i];//we placed another kid
        }
        //if at least min distance ni hai then move on to next iteation
    }
    return false;//we were not able to place all kids
}
int PlaceKidsAtStart(vector<int>& points,int k){
    sort(points.begin(),points.end());
    int l = 1;
    int r = points[points.size() - 1] - points[0];
    int ans = -1;
    while(l<=r){
        int mid = l + (r - l) / 2;
        if(canPlaceKids(points,mid,k)){
            ans = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return ans;
}
int main(){
    int n;//no of starting points
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n;i++){
        cin >> v[i];
    }
    int k;//kids
    cin >> k;
    cout << PlaceKidsAtStart(v, k)<<endl;
    return 0;
}