#include<bits/stdc++.h>
using namespace std;
// Hint 1:
// In a tree, the longest path always lies between two leaf nodes.
// But which two leaves exactly form this path?

// Hint 2:
// Try picking any arbitrary node and finding the farthest node from it.
// Observe what kind of node you reach.

// Hint 3:
// The farthest node from any starting node is guaranteed to be one end of the diameter.

// Hint 4:
// If you run the same search again from that farthest node,
// what do you think you’ll find at the end?

// Hint 5:
// The distance between these two farthest-apart nodes is the diameter of the tree.

pair<int,int> farthestNode(int n, vector<vector<int>>& graph,int start){
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int farthest = 0;
    int level = -1;
    while (!q.empty())
    {   
        int sz=q.size();
        level++;
        while(sz--){
            int node = q.front();
            q.pop();
            farthest = node;
            for (auto neigh : graph[node])
            {
                if (!visited[neigh])
                {
                    q.push(neigh);
                    visited[neigh] = true;
                }
            }
        }
    }
    return {farthest,level};
} 
int findDiameter(int n, vector<vector<int>> &edges)
{
    if (edges.empty())
        return 0;
    vector<vector<int>> graph(n);
    for (int i = 0; i < n - 1; i++)
    {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }

    pair<int,int> pp1=farthestNode(n,graph,0);
    pair<int,int> pp2=farthestNode(n,graph,pp1.first);
    return pp2.second;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> edges(n-1,vector<int>(2));
    for(int i=0;i<n-1;i++){
        cin>>edges[i][0]>>edges[i][1];
        edges[i][0]--;
        edges[i][1]--;
    }
    cout<<findDiameter(n,edges)<<endl;
    return 0;
}