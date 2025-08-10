// FIrst CODE IS GIVING TLE ON GFG
// 2nd code is fine
void backTrack(int i, int j, string &p, string &q, vector<vector<int>> &dp, string curr, set<string> &ans)
{
    if (i == p.size() or j == q.size())
    {
        ans.insert(curr);
        return;
    }
    if (p[i] == q[j])
    {

        backTrack(i + 1, j + 1, p, q, dp, curr + p[i], ans);
    }
    else
    {
        if (dp[i + 1][j] == dp[i][j])
        {
            backTrack(i + 1, j, p, q, dp, curr, ans);
        }
        if (dp[i][j + 1] == dp[i][j])
        {
            backTrack(i, j + 1, p, q, dp, curr, ans);
        }
    }
}
vector<string> findLCS(int n, int m, string &p, string &q)
{
    vector<vector<int>> dp(p.size() + 1, vector<int>(q.size() + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (p[i] == q[j])
            {
                dp[i][j] = 1 + dp[i + 1][j + 1];
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    if (dp[0][0] == 0)
        return {""};
    set<string> ans;
    backTrack(0, 0, p, q, dp, "", ans);
    return vector<string>(ans.begin(), ans.end());
}

vector<string> all_longest_common_subsequences(string s, string t)
{
    return findLCS(s.size(), t.size(), s, t);
}
