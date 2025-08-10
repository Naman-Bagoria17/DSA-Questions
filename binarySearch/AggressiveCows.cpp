#include<bits/stdc++.h>
using namespace std;
bool canCowsbePlaced(vector<int>& stalls,int mid,int c){
    int cowsPlaced = 1;
    int lastPlaced = stalls[0];
    for (int i = 0; i < stalls.size();i++){
        if (stalls[i]-lastPlaced>=mid){
            cowsPlaced++;
            if(cowsPlaced==c)
                return true;
            lastPlaced = stalls[i];
        }
    }
    return false;
}
int LargestMinDistanceBetweenCows(vector<int>& stalls, int c){
    sort(stalls.begin(), stalls.end());
    int l = 1;
    int r = stalls[stalls.size() - 1] - stalls[0];
    int ans = -1;
    while(l<=r){
        int mid = l + (r - l) / 2;
        if(canCowsbePlaced(stalls,mid,c)){
            //if min distance ye hai to isse km me to ni hoga
            //isse better min distance mile to dekhte hai, bdiya hai
            ans = mid;
            l = mid + 1;
        }
        else{
            //if this can't be minimum distance 
            //isse km hoga minimum distance
            r = mid - 1;
        }
    }
    return ans;
}
int main(){
    int s;
    cin >> s;
    vector<int> stalls;
    while(s--){
        int ele;
        cin >> ele;
        stalls.push_back(ele);
    }
    int c;
    cin >> c;
    cout << LargestMinDistanceBetweenCows(stalls, c) << endl;
}