// THESE ARE 2 MEMOIZATION APPROACHES, TABULAR ON LEETCODE

//  memoization 1
int f(vector<vector<int>> &dp, int a, vector<int> &coins, int i)
{
    if (a < 0 or i >= coins.size())
        return 0;
    if (a == 0)
        return 1;
    if (dp[i][a] != -1)
        return dp[i][a];
    int sum = a;
    int ways = 0;
    while (sum > 0)
    {
        ways += f(dp, sum, coins, i + 1);
        sum -= coins[i];
        if (sum == 0)
            ways++;
    }
    return dp[i][a] = ways;
}
int change(int amount, vector<int> &coins)
{
    vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
    return f(dp, amount, coins, 0);
}

// memoization 2
int f(vector<vector<int>> &dp, int a, vector<int> &coins, int i)
{
    if (a < 0 or i >= coins.size())
        return 0;
    if (a == 0)
        return 1;
    if (dp[i][a] != -1)
        return dp[i][a];
    int ex = f(dp, a, coins, i + 1);
    int in = f(dp, a - coins[i], coins, i);
    return dp[i][a] = in + ex;
}
int change(int amount, vector<int> &coins)
{
    vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
    return f(dp, amount, coins, 0);
}
