// SEE EXPLANATION ON NOTEBOOK
vector<int> dir = {-1, 0, 1};
vector<vector<vector<int>>> dp;
int f(int i, int j1, int j2, vector<vector<int>> &grid)
{
    if (j1 < 0 or j1 >= grid[0].size() or j2 < 0 or j2 >= grid[0].size())
        return 0;

    if (i == grid.size() - 1)
    {
        return (j1 == j2 ? grid[i][j1] : grid[i][j1] + grid[i][j2]);
    }

    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    int ans = 0;

    for (int d1 = 0; d1 < 3; d1++)
    {
        for (int d2 = 0; d2 < 3; d2++)
        {

            int nc1 = j1 + dir[d1];
            int nc2 = j2 + dir[d2];

            int currChoco = (j1 == j2 ? grid[i][j1] : grid[i][j1] + grid[i][j2]);

            ans = max(ans, currChoco + f(i + 1, nc1, nc2, grid));
        }
    }
    return dp[i][j1][j2] = ans;
}
int solve(int n, int m, vector<vector<int>> &grid)
{
    dp.resize(n, vector<vector<int>>(m, vector<int>(m, -1)));
    return f(0, 0, grid[0].size() - 1, grid);
}

// SPACE OPTIMIZED(BOTTOM UP)

int solve(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<int>> next(m, vector<int>(m, 0)), curr(m, vector<int>(m, 0));
    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
            {
                next[j1][j2] = grid[n - 1][j1];
            }

            else
                next[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                curr[j1][j2] = 0;
                for (int d1 = -1; d1 <= 1; d1++)
                {
                    for (int d2 = -1; d2 <= 1; d2++)
                    {
                        int nc1 = j1 + d1;
                        int nc2 = j2 + d2;
                        if (nc1 < 0 or nc2 < 0 or nc1 >= m or nc2 >= m)
                            continue;
                        int currChoco = (j1 == j2 ? grid[i][j1] : grid[i][j1] + grid[i][j2]);
                        curr[j1][j2] = max(curr[j1][j2], currChoco + next[nc1][nc2]);
                    }
                }
            }
        }
        next = curr;
    }
    return next[0][m - 1];
}
