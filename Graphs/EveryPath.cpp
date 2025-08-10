#include <bits/stdc++.h>
using namespace std;
vector<list<int>> graph;
unordered_set<int> visited;
vector<vector<int>> result;
void add_edge(int src, int des, bool bidirec)
{
    graph[src].push_back(des);
    if (bidirec)
        graph[des].push_back(src);
}
// void dfs(int curr,int end,vector<int> path){
//     if(curr==end){//lets say curr vertex becomes end vertex while travelling from neighbour to neighbour
//         path.push_back(curr);
//         result.push_back(path);
//         path.pop_back();
//         return;
//     }
//     path.push_back(curr);
//     visited.insert(curr);
//     for (auto neighbour : graph[curr])
//     {
//         if (!visited.count(neighbour))
//         {
//             dfs(neighbour, end,path);
//         }
//     }
//     path.pop_back();
//     visited.erase(curr);//so that I can discover every path
//     return ;
// }

// revision
void dfs(int src, int des, vector<int> &path)
{
    if (src == des)
    {
        path.push_back(src);
        result.push_back(path);
        path.pop_back();
        return;
    }
    path.push_back(src);
    visited.insert(src);
    for (auto neighbour : graph[src])
    {
        if (!visited.count(neighbour))
        {
            dfs(neighbour, des, path);
        }
    }
    path.pop_back(); // so that agr kisi node se saari possibilties explore krli ab usko path se hatao qki ab tum uski pichhe vaali node pe jaa rahe ho
    visited.erase(src);
    return;
}
void allPaths(int src, int dest)
{
    vector<int> path;
    dfs(src, dest, path);
}
void display()
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << "-> ";
        for (auto ele : graph[i])
        {
            cout << ele << " ,";
        }
        cout << endl;
    }
}
int main()
{
    int v;
    cin >> v;
    graph.resize(v, list<int>());
    int e;
    cin >> e;
    while (e--)
    {
        int src, des;
        cin >> src >> des;
        add_edge(src, des, true);
    }

    display();
    int x, y;
    cin >> x >> y;
    allPaths(x, y);
    cout << "Paths: " << endl;
    for (auto path : result)
    {
        for (auto ele : path)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}
