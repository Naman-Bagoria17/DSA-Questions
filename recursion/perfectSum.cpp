#include<bits/stdc++.h>
using namespace std;
//this approach is not using DP. It is just backtracking
void perfectSumHelper(vector<int> &arr, int currSum, int &target, int idx, int &ans)
{
    if (idx == arr.size())
    {
        if (currSum == target)
            ans++;
        return;
    }
    perfectSumHelper(arr, currSum, target, idx + 1, ans);
    perfectSumHelper(arr, currSum + arr[idx], target, idx + 1, ans);
}
int perfectSum(vector<int> &arr, int target)
{
    int ans = 0;
    perfectSumHelper(arr, 0, target, 0, ans);
    return ans;
}
int main()
{
    return 0;
}
