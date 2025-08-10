#include<bits/stdc++.h>
using namespace std;
vector<list<int>> graph;
int v;
void add_edge(int src,int des,bool bidirec){
    graph[src].push_back(des);
    if(bidirec)
        graph[des].push_back(src);
}
void topoBFS(){
    //KAHN'S ALGO
    //agr humare graph me koi cyclic subgraph exist krega to Topological sort beech me ruk jayega
    vector<int> indegree(v, 0);
    for (int i = 0; i < v;i++){
        for(auto neighbour:graph[i]){
            //i------->neighbour
            indegree[neighbour]++;
        }
    }
    queue<int> q;
    unordered_set<int> visited;

    //step of multisource BFS
    for (int i = 0; i < v;i++){
        if(indegree[i]==0){
            q.push(i);
            visited.insert(i);
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(auto neighbour:graph[node]){
            if(!visited.count(neighbour)){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }
    }
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
    topoBFS();
    return 0;
}
