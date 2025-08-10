// EXPLANATION OF EVERY APPROACH ON NOTEBOOK
//  BOTTOM UP ON GFG
vector<vector<int>> dp;
int f(int i, vector<int> &val, vector<int> &wt, int totWeight, int capacity)
{
    if (i == val.size())
        return 0;
    if (dp[i][totWeight] != -1)
        return dp[i][totWeight];

    int exclude = f(i + 1, val, wt, totWeight, capacity);
    int include = 0;
    if (totWeight + wt[i] <= capacity)
    {
        include = val[i] + f(i, val, wt, totWeight + wt[i], capacity);
    }
    return dp[i][totWeight] = max(include, exclude);
}
int knapSack(vector<int> &val, vector<int> &wt, int capacity)
{
    // code here
    dp.resize(val.size() + 5, vector<int>(capacity + 5, -1));
    return f(0, val, wt, 0, capacity);
}

// tabulation also on gfg and coding ninjas
vector<vector<int>> dp;
int knapSack(vector<int> &val, vector<int> &wt, int capacity)
{
    // code here
    dp.clear();
    int n = val.size();
    dp.resize(n, vector<int>(capacity + 1, 0));

    for (int w = 0; w <= capacity; w++)
    {
        dp[0][w] = ((int)(w / wt[0])) * val[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        { // similar to memoization(see that approach also)

            dp[i][w] = dp[i - 1][w]; // exclude
            if (wt[i] <= w)
            {
                dp[i][w] = max(dp[i][w], val[i] + dp[i][w - wt[i]]); // include multiple times
            }
        }
    }

    return dp[n - 1][capacity];
}

// space optimized-> 2 1-D arrays
int knapSack(vector<int> &val, vector<int> &wt, int capacity)
{
    // code here
    int n = val.size();
    vector<int> prev(capacity + 1, 0), curr(capacity + 1, 0);

    for (int w = 0; w <= capacity; w++)
    {
        prev[w] = ((int)(w / wt[0])) * val[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        { // similar to memoization(see that approach also)

            curr[w] = prev[w]; // exclude
            if (wt[i] <= w)
            {
                curr[w] = max(curr[w], val[i] + curr[w - wt[i]]); // include multiple times
            }
        }
        prev = curr;
    }

    return prev[capacity];
}

// space optimized- single 1d array
int knapSack(vector<int> &val, vector<int> &wt, int capacity)
{
    // code here
    int n = val.size();
    vector<int> prev(capacity + 1, 0);
    for (int w = 0; w <= capacity; w++)
    {
        prev[w] = ((int)(w / wt[0])) * val[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        { // similar to memoization(see that approach also)

            if (wt[i] <= w)
            {
                prev[w] = max(prev[w], val[i] + prev[w - wt[i]]); // include multiple times
            }
        }
    }

    return prev[capacity];
}