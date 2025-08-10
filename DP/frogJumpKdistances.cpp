// THIS IS MEMOIZATION, BOTTOM UP ON GFG
vector<int> dp;
int f(vector<int> &arr, int i, int k)
{
    if (i == arr.size() - 1)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int ans = INT_MAX;
    for (int j = i + 1; j <= i + k; j++)
    {
        if (j >= arr.size())
            break;
        ans = min(ans, abs(arr[i] - arr[j]) + f(arr, j, k));
    }

    return dp[i] = ans;
}
int minimizeCost(int k, vector<int> &arr)
{
    dp.clear();
    dp.resize(arr.size(), -1);
    return f(arr, 0, k);
}
