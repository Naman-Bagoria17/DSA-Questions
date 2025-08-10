#include<bits/stdc++.h>
using namespace std;
int v;//no of vertices
vector<list<int>> graph;
unordered_set<int> visited;
void add_edge(int src,int des,bool bidirec){
    graph[src].push_back(des);
    if(bidirec)
        graph[des].push_back(src);
}
void shortest_paths(int src,vector<int> &dist){
    queue<int> q;
    visited.clear();//bcz it is global
    visited.insert(src);
    q.push(src);
    dist.resize(v, -1);
    dist[src] = 0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        cout << curr << " ";
        for(auto neighbour:graph[curr]){
            if(!visited.count(neighbour)){
                q.push(neighbour);
                visited.insert(neighbour);
                dist[neighbour] = dist[curr] + 1;
            }
        }
    }
    cout << endl;
} 
int main(){
    cin >> v;
    graph.resize(v,list<int> ());
    int e;
    cin >> e;   
    while(e--){
        int src, des;
        cin >> src >> des;
        add_edge(src, des, true);
    }
    int x;
    cout << "Enter source vertex: ";
    cin >> x;
    vector<int> dist;
    cout << "BFS: ";
    shortest_paths(x, dist);
    cout << "Shortest distances from source: ";
    for(auto ele:dist){
        cout << ele << " ";
    }
    return 0;
}