#include<bits/stdc++.h>
using namespace std;
int v;
vector<list<int>> graph;
void add_edge(int src,int des,bool bidirec){
    graph[src].push_back(des);
    if(bidirec)
        graph[des].push_back(src);
}
// void dfs(int node,unordered_set<int> &visited){
//     visited.insert(node);
//     for(auto neighbour:graph[node]){
//         if(!visited.count(neighbour)){
//             dfs(neighbour, visited);
//         }
//     }
// }
// int connected_component(){
//     int result = 0;
//     unordered_set<int> visited;
//     for (int i = 0; i < v;i++){
//         //go to every vertex
//         //if from a vertex we can initialize a dfs we got a connected component
//         if(visited.count(i)==0){
//             result++;
//             dfs(i, visited);
//         }
//     }
//     return result;
// }

// //Revision
// void dfs(int curr,unordered_set<int> &visited){
//     visited.insert(curr);
//     for(auto neighbour:graph[curr]){
//         if(!visited.count(neighbour)){
//             dfs(neighbour, visited);
//         }
//     }
// }
// int connected_component(){
//     unordered_set<int> vis;
//     int conn_comp = 0;
//     for (int i = 0; i < v;i++)
//     {
//         if(!vis.count(i)){
//             conn_comp++;
//             dfs(i, vis);
//         }
//     }
//     return conn_comp;
// }

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
    cout << "connected components: "<<connected_component();
    return 0;
}


