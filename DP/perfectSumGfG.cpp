// SEE EXPLANATION ON NOTEBOOK
// TWIST HERE IS TARGET CAN BE ZERO AND ELEMENTS CAN BE ZERO
// CODE ALSO ON GFG
int perfectSumHelper(vector<int> &arr, int remSum, int idx, vector<vector<int>> &dp)
{
    if (idx == arr.size() - 1)
    {
        if (remSum == 0 and arr[idx] == 0)
            return 2;
        if (remSum == 0 or remSum == arr[idx])
            return 1;
        return 0;
    }
    if (idx == arr.size() or remSum < 0)
        return 0;

    if (dp[idx][remSum] != -1)
        return dp[idx][remSum];

    int exclude = perfectSumHelper(arr, remSum, idx + 1, dp);
    int include = 0;
    if (remSum >= arr[idx])
        include = perfectSumHelper(arr, remSum - arr[idx], idx + 1, dp);

    return dp[idx][remSum] = include + exclude;
}
int perfectSum(vector<int> &arr, int target)
{
    vector<vector<int>> dp(arr.size() + 1, vector<int>(target + 1, -1));
    return perfectSumHelper(arr, target, 0, dp);
}
