#include<bits/stdc++.h>
using namespace std;
int max_area_rec(vector<int> heights){
    stack<int> s;
    int ans = INT_MIN;
    s.push(heights[0]);
    for (int i = 1; i < heights.size();i++)
    { 
        while(!s.empty() && heights[i]<heights[s.top()]){//s ke top pe element wait kr raha hai kb usko nse milega
            int ele = heights[s.top()];
            s.pop();
            int nse = i;//jo abhi element mila mtlb ko current stack ke top ke liye nse hai
            int pse = (s.empty()) ? (-1) : s.top();
            ans = max(ans, ele * (nse - pse - 1));
        }
        s.push(i);//jaise hi hume NSE mil jayega we will come out of while loop
        //current element ke liye nse nikalna hai to use stack me  to daalo
    }
    // ho skta hai abhi stack empty na hua ho
    //  mtlb kuchh elements ke liye nse and pse ni mila;
    while(!s.empty()){
            int ele = heights[s.top()];
            s.pop();
            int nse = heights.size();
            int pse = (s.empty()) ? (-1) : s.top();
            ans = max(ans, ele * (nse - pse - 1));
    }
    return ans;
}
int main(){
    vector<int> heights = {2,1,5,6,2,3,0,2,1,5,6,2,3};
    cout << max_area_rec(heights);
}