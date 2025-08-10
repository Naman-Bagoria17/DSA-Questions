#include<bits/stdc++.h>
using namespace std;
vector<list<int>> graph;
unordered_set<int> visited;
int v;
void add_edge(int src,int des,bool bidirec){
    graph[src].push_back(des);
    if(bidirec)
        graph[des].push_back(src);
}

bool bfs(int src){
    visited.insert(src);
    queue<int> q;
    vector<int> parent(v,-1);
    q.push(src);
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        for(auto neighbour:graph[curr]){
            if(visited.count(neighbour) and parent[curr]!=neighbour)
                return true;//cycle detected
            if(!visited.count(neighbour)){
                visited.insert(neighbour);
                parent[neighbour] = curr;
                q.push(neighbour);
            }
        }
    }
    return false;
} 
bool hasCycle(){
    for (int i = 0; i < v;i++){
        if(!visited.count(i)){
            bool result = bfs(i);
            if(result==true)
                return true;
        }
    }
    return false;//all vertices visited but cycle not detected
}
int main(){
    cin >> v;
    graph.resize(v,list<int> ());
    int e;
    cin >> e;   
    while(e--){
        int src, des;
        cin >> src >> des;
        add_edge(src, des, false);
    }
    cout << hasCycle();
    return 0;
}