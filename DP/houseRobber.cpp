// I have done bottom up on leetcode which is more optimal
vector<int> dp;
int Helper(vector<int> &a, int idx)
{
    if (idx >= a.size())
    {
        return 0;
    }
    if (dp[idx] != -1)
        return dp[idx];
    return dp[idx] = max(Helper(a, idx + 2) + a[idx], Helper(a, idx + 1));
}
int rob(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];
    if (nums.size() == 2)
        return max(nums[0], nums[1]);
    dp.resize(nums.size(), -1);
    return Helper(nums, 0);
}
