#include <bits/stdc++.h>
using namespace std;
vector<bool> used;
bool f(int i, int subsetNum, int subsetSum, int reqSum, vector<int> &nums,
       int k)
{
    if (subsetNum == k + 1)
        return true;
    if (subsetSum == reqSum)
    {
        return f(0, subsetNum + 1, 0, reqSum, nums, k);
    }
    if (i == nums.size())
        return false;

    if (used[i])
    {
        return f(i + 1, subsetNum, subsetSum, reqSum, nums, k);
    }
    bool op1 = false;
    if (subsetSum + nums[i] <= reqSum)
    {
        used[i] = true;
        op1 = f(i + 1, subsetNum, subsetSum + nums[i], reqSum, nums, k);
        used[i] = false;
    }
    bool op2 = f(i + 1, subsetNum, subsetSum, reqSum, nums, k);

    return op1 || op2;
}
bool canPartitionKSubsets(vector<int> &nums, int k)
{
    int n = nums.size();
    int totalSum = accumulate(nums.begin(), nums.end(), 0);

    if (totalSum % k != 0)
        return false;
    int reqSum = totalSum / k;
    sort(nums.begin(), nums.end(), greater<int>());
    used.resize(n, false);
    return f(0, 1, 0, reqSum, nums, k);
}
