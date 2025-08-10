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

bool dfs(int curr,int parent){
    visited.insert(curr);
    for(auto neighbour:graph[curr]){
        if(visited.count(neighbour) and neighbour!=parent){
            // cycle detected
            return true;
        }
        if(!visited.count(neighbour)){
            bool res=dfs(neighbour, curr);//qki recursive calls ka result waapis yaha pe hi aayega
            if(res==true)
                return true;
        }
    }
    //cycle not detected
    return false;
} 
bool hasCycle(){
    for (int i = 0; i < v;i++){
        if(!visited.count(i)){
            bool result = dfs(i, -1);
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