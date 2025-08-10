#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int find(vector<int>& parent,int x){
    return parent[x] = (parent[x] == x) ? x : find(parent,parent[x]);
}
void Union(vector<int> &parent,vector<int> &rank,int a,int b){
    //when we are calling  Union function we are calling it after
    //comparing the parents of src and dest so no need to compare here
    if (rank[a] >= rank[b]){
        rank[a]++;
        parent[b] = a;
    }
    else{
        rank[b]++;
        parent[a] = b;
    }
}
class Edge{
    public:
        int src;
        int des;
        int wt;
};
bool cmp(Edge e1,Edge e2){
    return e1.wt < e2.wt;
}
//overall TC- O(v+eloge) 
ll kruskals(vector<Edge>& input,int n,int e){
    sort(input.begin(), input.end(), cmp);//eloge
    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 1);
    for (int i = 1; i <= n;i++){
        parent[i] = i; 
    }
    int ans = 0;//keep track of weight of MST
    int edgeCount = 0;//to keep track how many edges we picked for our subgraph
    // edge count should be n-1 where n->vertices
    int i = 0;//to iterate over input vector
    while (edgeCount < n - 1/*no need for edge count condition bcz ofcourse
     edges will be n-1 to get a connected componen with minimum edges*/ 
     and i < input.size()){//(n-1)times loop run  nearly O(nlog*n) where n->vertices
        auto edge = input[i];//this will give the minimum weight edge
        int srcPar = find(parent, edge.src);
        int desPar = find(parent, edge.des);
        if(srcPar!=desPar){//means both vertices are not in same group and would not form a cycle
            //so we can include the edge
            Union(parent, rank, srcPar, desPar);//merge both the groups.i.e why we passed parents
            ans += edge.wt;
            edgeCount++;
        }
        i++;//traversing to next edge in the input
    }
    return ans;
}
int main(){
    int n, e;
    cin >> n >> e;
    vector<Edge> v(e);
    for (int i = 0; i < e; i++){
        cin >> v[i].src >> v[i].des >> v[i].wt;
    }
    cout << kruskals(v, n, e) << endl;
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// int find(vector<int>& parent,int x){
//     return parent[x] = (parent[x] == x) ? x : find(parent,parent[x]);
// }
// bool Union(vector<int>& parent,vector<int>& rank,int src,int des){
//     int srcPar = find(parent, src);
//     int desPar = find(parent, des);
//     if(srcPar==desPar)
//         return true;//means cycle exists
//     if(rank[srcPar]<=rank[desPar]){
//         parent[srcPar] = desPar;
//         rank[desPar]++;
//     }
//     else{
//         rank[srcPar]++;
//         parent[desPar] = srcPar;
//     }
//     return false;
// }
// class Edge{
//     public:
//         int src;
//         int des;
//         int wt;
// };
// bool cmp(Edge e1, Edge e2){ return e1.wt < e2.wt;}
// int kruskals(vector<Edge> edges,int v,int e){
//     sort(edges.begin(), edges.end(),cmp);
//     vector<int> par(v + 1);
//     for (int i = 1; i <= v;i++){
//         par[i] = i;
//     }
//     vector<int> rank(v + 1, 0);
//     int edgeWt = 0;
//     int totalEdges = v - 1;
//     int i = 0;
//     while( i<edges.size() and totalEdges>0){
//         auto curr = edges[i];
//         int src = curr.src;
//         int des = curr.des;
//         bool hasCycle = Union(par, rank, src, des);
//         if(!hasCycle){
//             edgeWt += curr.wt;
//             totalEdges--;
//         }
//         i++;
//     }
//     return edgeWt;
// }
// int main(){
//     int v,e;
//     cin >> v >> e;
//     vector<Edge> edges;
//     for (int i = 0; i < e;i++){
//         Edge edge;
//         cin >> edge.src >> edge.des >> edge.wt;
//         edges.push_back(edge);
//     }
//     cout << kruskals(edges, v, e);
//     return 0;
// }



