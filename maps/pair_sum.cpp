// Given an array of length n and a target sum
// return indices of the elements whose sum is equal to the target
//  if absent return -1
#include<bits/stdc++.h>
using namespace std;
int main(){
    int target;
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> v(n);
    vector<int> ans(2, -1);
    int i = 0;
    while(n--){
        cin >> v[i];
        i++;
    }
    cout << "Enter the target sum: ";
    cin >> target;
    unordered_map<int, int> m;//element-index
    for (int i = 0; i < v.size();i++)
    {
        auto itr = m.find(target - v[i]);
        if(itr!=m.end()){//means we found the pair
            ans[0] = itr->second;
            ans[1] = i;
            break;
        }
        else{
            m[v[i]] = i;
        }
    }
    cout << ans[0] << ", " << ans[1];

    // TC-O(n)
    // SC-O(n) 
}