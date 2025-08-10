// BOTH APPROACHES EXPLANATION ON NOTEBOOK(MUST SEE)
//  MEMOIZATION
int maxAns = 0;
vector<vector<int>> dp;
int f(string &s1, string &s2, int i, int j)
{
    if (i == s1.size() or j == s2.size())
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int match = 0;
    if (s1[i] == s2[j])
        match = 1 + f(s1, s2, i + 1, j + 1);
    int notMatch = max(f(s1, s2, i + 1, j), f(s1, s2, i, j + 1));
    maxAns = max({maxAns, match, notMatch});

    return dp[i][j] = match; // this is the best answer found till this stage.
}
int longestCommonSubstr(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();
    maxAns = 0;
    dp.clear();
    dp.resize(n, vector<int>(m, -1));
    f(s1, s2, 0, 0);
    return maxAns;
}

// TABULATION
int longestCommonSubstr(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();
    int maxAns = 0;
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s1[i] == s2[j])
            {
                dp[i][j] = 1 + (i - 1 >= 0 and j - 1 >= 0 ? dp[i - 1][j - 1] : 0);
                maxAns = max(maxAns, dp[i][j]);
            }
        }
    }
    return maxAns;
}

// SPACE OPTIMIZED( two 1-D arrays)
int longestCommonSubstr(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();
    int maxAns = 0;
    vector<int> curr(m, 0), prev(m, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s1[i] == s2[j])
            {
                curr[j] = 1 + (j - 1 >= 0 ? prev[j - 1] : 0);
                maxAns = max(maxAns, curr[j]);
            }
            else
                curr[j] = 0; // you need to reset the value for particular j ni to aage vaale
            // cases me purana curr[j] use hojayega as we are doing prev=curr;
        }
        prev = curr;
    }
    return maxAns;
}

// Single 1-D array
// EXPLANATION ON NOTEBOOK(MUST SEE)
int longestCommonSubstr(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();
    int maxAns = 0;
    vector<int> curr(m, 0);

    for (int i = 0; i < n; i++)
    {
        int prevVal = 0;
        for (int j = 0; j < m; j++)
        {
            int temp = curr[j];
            if (s1[i] == s2[j])
            {
                curr[j] = 1 + (j - 1 >= 0 ? prevVal : 0);
                maxAns = max(maxAns, curr[j]);
            }
            else
                curr[j] = 0;
            prevVal = temp;
        }
    }
    return maxAns;
}
