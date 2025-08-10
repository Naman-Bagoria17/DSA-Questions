#include <bits/stdc++.h>
using namespace std;

// EXPLANATION ON NOTEBOOK
string findLCS(int n, int m, string &p, string &q)
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
        return "";
    string ans = "";
    int i = 0, j = 0;
    while (i < n and j < m)
    {
        if (p[i] == q[j])
        {
            ans += p[i];
            i++;
            j++;
        }
        else if (dp[i + 1][j] > dp[i][j + 1])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return ans;
}
