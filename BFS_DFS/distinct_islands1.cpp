#include<bits/stdc++.h>
using namespace std;
//we have to check the pattern of every island and that we can check by knowing the relative postion of every cell in the component from the cell which started the bfs.
vector<vector<int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
void bfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &vis,
         set<vector<pair<int, int>>> &pat)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<pair<int, int>> currPat;
    queue<pair<int, int>> q;
    vis[i][j] = true;
    q.push({i, j});
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        currPat.push_back({r - i, c - j});
        q.pop();
        for (int d = 0; d < 4; d++)
        {
            int nr = r + dir[d][0];
            int nc = c + dir[d][1];
            if (nr < 0 || nc < 0 || nr == n || nc == m || vis[nr][nc] || grid[nr][nc] == 0)
                continue;
            vis[nr][nc] = true;
            q.push({nr, nc});
        }
    }
    pat.insert(currPat);
}
int countDistinctIslands(vector<vector<int>> &grid)
{
    // code here
    set<vector<pair<int, int>>> pat;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == 1)
            {
                bfs(i, j, grid, vis, pat);
            }
        }
    }
    return pat.size();
}
