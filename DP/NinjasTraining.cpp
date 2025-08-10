// THIS IS MEMOIZATION WHICH IS SUB-OPTIMAL DUE TO RECURSION SIZE
// BELOW IS TABULATION APPROACH
vector<vector<int>> dp;
int f(vector<vector<int>> &grid, int r, int c)
{
    if (r == grid.size() - 1)
        return grid[r][c];
    if (dp[r][c] != -1)
        return dp[r][c];
    int maxPoints = INT_MIN;
    for (int i = 0; i < 3; i++)
    {
        if (i == c)
            continue;
        maxPoints = max(maxPoints, f(grid, r + 1, i));
    }
    return dp[r][c] = grid[r][c] + maxPoints;
}
int maximumPoints(vector<vector<int>> &arr)
{
    dp.resize(arr.size(), vector<int>(3, -1));
    int ans = f(arr, 0, 0);
    dp.resize(arr.size(), vector<int>(3, -1));
    ans = max(ans, f(arr, 0, 1));
    dp.resize(arr.size(), vector<int>(3, -1));
    ans = max(ans, f(arr, 0, 2));
    return ans;
}

// TABULATION
vector<vector<int>> dp;
int maximumPoints(vector<vector<int>> &arr)
{
    int n = arr.size();
    dp.resize(n, vector<int>(3, INT_MIN));
    for (int i = 0; i < 3; i++)
    {
        dp[n - 1][i] = arr[n - 1][i];
    }
    for (int r = n - 2; r >= 0; r--)
    {
        for (int c = 0; c < 3; c++)
        {
            for (int i = 0; i < 3; i++)
            {
                if (i == c)
                    continue;
                dp[r][c] = max(dp[r][c], arr[r][c] + dp[r + 1][i]);
            }
        }
    }
    return max({dp[0][0], dp[0][1], dp[0][2]});
}
