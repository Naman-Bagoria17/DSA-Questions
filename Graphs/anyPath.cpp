#include<bits/stdc++.h>
using namespace std;
vector<list<int>> graph;
// unordered_set<int> visited;
void add_edge(int src,int des,bool bidirec=true){
    graph[src].push_back(des);
    if(bidirec)
        graph[des].push_back(src);
}
//TC-O(V+E) bcz from every vertex we explored every edge 
//or we can say we travelled every vertex and every edge
//SC-O(V) recursion stack
// bool dfs(int curr,int end){
//     if(curr==end)//lets say curr vertex becomes end vertex while travelling from neighbour to neighbour 
//         return true;
//     visited.insert(curr);
//     for(auto neighbour:graph[curr]){
//         if(!visited.count(neighbour)){
//             bool result=dfs(neighbour, end);
//             if(result)
//                 return true;
//         }
//     }
//     return false;//we reached here bcz there is no unvisted vertex from this vertex and
//     //still we didn't find any path
//     // we reached at vertex from where we can't move further
// } 
// bool anyPath(int src,int dest){
//     return dfs(src, dest);
// }
// bool anyPath(int src,int des,unordered_set<int> &vis){
//     if(src==des)
//         return true;
//     vis.insert(src);
//     for(auto neighbour: graph[src]){
//         if(!vis.count(neighbour)){
//             bool res = anyPath(neighbour, des, vis);
//             if(res==true)
//                 return true;//agr kabhi bhi path mil jaaata hai
//         }
//     }
//     return false;
// }
// void dfs_usingStack(int src){
//     unordered_set<int> vis;
//     stack<int> s;
//     s.push(src);
//     while(!s.empty()){
//         int curr = s.top();
//         s.pop();
//         cout << curr << " ";
//         vis.insert(curr);
//         for(auto neighbour:graph[curr]){
//             if(!vis.count(neighbour)){
//                 s.push(neighbour);
//             }
//         }
//     }
//     cout << endl;
// }
// void display(){
//     for (int i = 0; i < graph.size(); i++){
//         cout << i << "-> ";
//         for(auto ele:graph[i]){
//             cout << ele << " ,";
//         }
//         cout << endl;
//     }
// }
int main(){
    int v;
    cin >> v;
    graph.resize(v,list<int> ());
    int e;
    cin >> e;   
    while(e--){
        int src, des;
        cin >> src >> des;
        add_edge(src, des,false);
    }

    // display();
    // int x, y;
    // cin >> x >> y;
    // unordered_set<int> vis;
    // cout << anyPath(x, y,vis);
    // dfs_usingStack(0);
    return 0;
}


