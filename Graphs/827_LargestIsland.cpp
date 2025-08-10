// CODE GIVES TLE ON LEETCODE
class Solution
{
public:
    vector<vector<int>> dir = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int largeIsland = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    int ones = 0;
                    bfs(grid, i, j, ones);
                    largeIsland = max(ones, largeIsland);
                }
            }
        }
        if (largeIsland == 0)
            return n * n;
        return largeIsland;
    }

    void bfs(vector<vector<int>> &grid, int i, int j, int &ones)
    {
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({i, j});

        while (!q.empty())
        {
            auto [row, col] = q.front();
            q.pop();
            ones++;
            for (int d = 0; d < 4; d++)
            {
                int nr = row + dir[d][0];
                int nc = col + dir[d][1];
                if (nc < 0 or nr < 0 or nc >= n or nr >= n)
                    continue;
                if (vis[nr][nc])
                    continue;
                if (grid[nr][nc] == 1)
                {
                    q.push({nr, nc});
                    vis[nr][nc] = true;
                }
            }
        }
        cout << endl;
    }
};