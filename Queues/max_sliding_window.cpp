// Return array of max elements in a sliding window of 
//size k moving from left to right in an given array

#include<bits/stdc++.h>
using namespace std;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;//To store indices of elements in the window
        vector<int> ans;
        //for first window
        for(int i=0;i<k;i++){
            while(!dq.empty() && nums[i]>nums[dq.back()] ){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        //for further widnows (if any)
        for(int i=k;i<nums.size();i++){
            if(dq.front()==(i-k))dq.pop_front();//basically ek window khtm hui
            while(!dq.empty() && nums[i]>nums[dq.back()] ){
                dq.pop_back();
            }
            dq.push_back(i);     
            ans.push_back(nums[dq.front()]); 
        }
        return ans;
    }
int main(){
    vector<int> nums={1,3,-1,-3,5,3,6,7};
    int k;
    cout << "Enter the size of window: ";
    cin >> k;
    vector<int> result = maxSlidingWindow(nums, k);
    cout << "Ans: ";
    for (int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
}