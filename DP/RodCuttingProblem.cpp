// EXPLANATION ON NOTEBOOK
// MEMOIZATION
vector<vector<int>> dp;
int f(int i, int len, vector<int> &price)
{
    if (i == price.size() - 1)
    {
        // agr mai last index pe hu to bachi hui length isko deskte ho to dedo
        return ((int)len / (i + 1)) * price[i];
    }

    if (dp[i][len] != -1)
        return dp[i][len];

    int exc = f(i + 1, len, price);
    int inc = 0;
    if (len >= i + 1)
    {
        inc = price[i] + f(i, len - (i + 1), price);
    }
    return dp[i][len] = max(inc, exc);
}
int cutRod(vector<int> &price)
{
    dp.clear();
    int n = price.size();
    dp.resize(n, vector<int>(n + 1, -1));
    return f(0, n, price);
}

// BEST SPACE OPTIMIZED
int cutRod(vector<int> &price)
{
    int n = price.size();
    vector<int> prev(n + 1, 0);

    prev[0] = 0;

    for (int i = 0; i <= n; i++)
    {
        for (int len = 1; len <= n; len++)
        {
            if (len >= i + 1)
            {
                prev[len] = max(prev[len], price[i] + prev[len - (i + 1)]);
            }
        }
    }

    return prev[n];
}
