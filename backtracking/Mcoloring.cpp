bool isSafe(vector<vector<int>> &graph, vector<int> &color, int c, int i)
{
    for (auto neighbour : graph[i])
    {
        if (color[neighbour] == c)
            return false;
    }
    return true;
}
bool Helper(vector<vector<int>> &graph, vector<int> &color, int m, int i)
{
    if (i == graph.size())
        return true;
    for (int c = 1; c <= m; c++)
    {
        if (isSafe(graph, color, c, i))
        {
            color[i] = c;
            if (Helper(graph, color, m, i + 1))
                return true;
            color[i] = -1;
        }
    }
    return false;
}
bool graphColoring(int v, vector<pair<int, int>> &edges, int m)
{
    vector<vector<int>> graph(v);
    for (auto &edge : edges)
    {
        graph[edge.first].push_back(edge.second);
        graph[edge.second].push_back(edge.first);
    }
    vector<int> color(v, -1);
    return Helper(graph, color, m, 0);
}
