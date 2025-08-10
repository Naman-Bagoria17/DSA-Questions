#include <bits/stdc++.h>
vector<vector<int>> dp;
int f(int i, int order, vector<int> &arr)
{
    int n = arr.size();
    if (i == n - 1)
        return 1;
    if (dp[i][order] != 0)
        return dp[i][order];
    int lbs = 1;
    for (int j = i + 1; j < n; j++)
    {
        if (order == 0)
        {
            if (arr[j] > arr[i])
            {
                lbs = max(lbs, 1 + f(j, 0, arr));
                lbs = max(lbs, 1 + f(j, 1, arr));
            }
        }
        else
        {
            if (arr[j] < arr[i])
            {
                lbs = max(lbs, 1 + f(j, 1, arr));
            }
        }
    }
    return dp[i][order] = lbs;
}
int longestBitonicSubsequence(vector<int> &arr, int n)
{
    // Write your code here.
    dp.clear();
    dp.resize(n, vector<int>(2, 0));
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans = max({ans, f(i, 0, arr), f(i, 1, arr)});
    }
    return ans;
}
