// SEE EXPLANATION ON NOTEBOOK
// THIS MEMOIZATION CODE ALSO ON GFG
vector<int> arr;
vector<vector<int>> dp;
bool f(int i, int target)
{
    if (target == 0)
        return true;
    if (i == arr.size())
        return false;
    if (dp[i][target] != -1)
        return dp[i][target];
    bool res1 = false, res2 = false;
    if (target - arr[i] >= 0)
        res1 = f(i + 1, target - arr[i]);
    res2 = f(i + 1, target);
    return dp[i][target] = res1 or res2;
}
bool isSubsetSum(vector<int> &nums, int target)
{
    arr = nums;
    dp.clear();
    dp.resize(nums.size(), vector<int>(target + 1, -1));
    return f(0, target);
}
