// MUST SEE INTUTION AND EVERY APPROACH ON NOTEBOOK

// MEMOIZATION I->THIS IS GIVING MLE ERROR IN LEETCODE
// TC->N^2  SC->N^2
vector<vector<int>> dp;
int f(int i, int lastBuy, vector<int> &prices)
{
    if (i == prices.size())
        return 0;

    if (lastBuy == -1)
    {
        return max(f(i + 1, i, prices), f(i + 1, -1, prices));
    }

    if (dp[i][lastBuy] != -1)
        return dp[i][lastBuy];

    int profit = 0;
    if (prices[i] > prices[lastBuy])
    {
        profit = prices[i] - prices[lastBuy];
    }

    return dp[i][lastBuy] = max(profit + f(i + 1, -1, prices), f(i + 1, lastBuy, prices));
}
int maxProfit(vector<int> &prices)
{
    dp.clear();
    int n = prices.size();
    dp.resize(n, vector<int>(n, -1));
    return f(0, -1, prices);
}

// MEMOIZATION II-> TC->2N AND SC->2N
vector<vector<int>> dp;
int f(int i, int buy, vector<int> &prices)
{
    if (i == prices.size())
        return 0;

    if (dp[i][buy] != -1)
        return dp[i][buy];
    int buyOrNot = 0;
    if (buy == 0)
    {
        buyOrNot = max(-prices[i] + f(i + 1, 1, prices), f(i + 1, 0, prices));
    }
    int sellOrNot = 0;
    if (buy == 1)
    {
        sellOrNot = max(prices[i] + f(i + 1, 0, prices), f(i + 1, 1, prices));
    }

    return dp[i][buy] = max(buyOrNot, sellOrNot);
}
int maxProfit(vector<int> &prices)
{
    dp.clear();
    int n = prices.size();
    dp.resize(n, vector<int>(2, -1));
    return f(0, 0, prices);
}

// 3rd app->TABULATION VERSION OF 2nd app on vscode

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        // buy or not buy
        dp[i][0] = max(-prices[i] + dp[i + 1][1], dp[i + 1][0]);

        // sell or not sell
        dp[i][1] = max(prices[i] + dp[i + 1][0], dp[i + 1][1]);
    }

    return dp[0][0];
}

// OTHER TWO SPACE OPTIMIZED APPROACHES ON LEETCODE
