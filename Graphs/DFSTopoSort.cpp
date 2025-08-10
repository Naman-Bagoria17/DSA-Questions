#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vis, stack<int> &st, vector<vector<int>> &adj)
{
    vis[node] = true;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, st, adj);
        }
    }
    st.push(node); // pehle node ke saare neighbours stack me push honge qki unki indegree hogi
    // last me node push hogi aur qki node top pe padi hai it will be read out first
}

vector<int> topologicalSort(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> vis(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, st, adj);
        }
    }
    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
