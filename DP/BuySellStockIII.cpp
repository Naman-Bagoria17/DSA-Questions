// ALL APPROACH EXPLANATIONS ON NOTEBOOK
// MEMOIZATION
vector<vector<int>> dp;
int f(int i, int transactions, vector<int> &prices)
{
    if (i == prices.size() or transactions == 4)
        return 0;

    if (dp[i][transactions] != -1)
        return dp[i][transactions];

    int nothing = f(i + 1, transactions, prices);
    int buyOrSell = 0;
    if (transactions % 2 == 0)
    {   //buy
        buyOrSell = -prices[i] + f(i + 1, transactions + 1, prices);
    }
    else
    {   //sell
        buyOrSell = prices[i] + f(i + 1, transactions + 1, prices);
    }
    return dp[i][transactions] = max(buyOrSell, nothing);
}

int maxProfit(vector<int> &prices)
{
    dp.clear();
    int n = prices.size();
    dp.resize(n, vector<int>(4, -1));
    return f(0, 0, prices);
}
// remaining 4 approaches on leetcode