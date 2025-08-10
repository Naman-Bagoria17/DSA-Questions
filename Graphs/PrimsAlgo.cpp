// Data structures- Visited set, unordered map, priority queue

// -insert the pair <0,src> in the pq;
// -one by one remove the front element
// -if the front ele is already visited then just contiue
// -mark the front ele visited
// -we store the weight of the pair in the ans
// -update the mapping if the weight is less
// -go to every neighbour of the front ele, and only add those which are non visited

#include<bits/stdc++.h>
# define ll long long int
# define pp pair<int,int>
using namespace std;
vector<list<pp>> graph; // ith ele will represent a list of neighbours of i with their weight
void add_edge(int u,int v,int wt,bool bidir=true){
    graph[u].push_back({v, wt});
    if(bidir){
        graph[v].push_back({u, wt});
    }
}
// one thing to remember- graph me jo ith element hai 
// that is list of pairs where pair.first is 
// neighbour and pair.second is its weight
// through i

// and Priority queue me jo pair.first hai that is weight through which the node is discovered
// and pair.second is Node which is discovered
ll prims(int src,int n){
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    unordered_set<int> vis;
    vector<int> par(n+1);//agr MST print krana hua to iski help se hojayega
    unordered_map<int, int> m;//storing node---discovery wt
    for (int i = 1; i <= n; i++){//bcz of one based indexing
        m[i] = INT_MAX;
    }
    pq.push({0, src});
    m[src] = 0;
    int total_count = 0; //we need n-1 edges to uska track rakhne ke liye
    int res = 0; //sum of weights
    while(total_count<n && !pq.empty()){
        auto curr = pq.top();
        pq.pop();
        vis.insert(curr.second); // jaise hi queue se bahar nikla mark it visited
        res += curr.first;
        for (auto neighbour : graph[curr.second]){
            if(!vis.count(neighbour.first)/*visited set will also help ki koi bhi apne parent pe na jaye*/ and m[neighbour.first]>neighbour.second){//we found a better edge
                pq.push({neighbour.second, neighbour.first});
                //also update the parent
                par[neighbour.first] = curr.second;
                m[neighbour.first] = neighbour.second;
            }
        }
        total_count++; // a new edge found everytime;
    }
    return res;
}

int main(){
    int n, e;
    cin >> n >> e;
    graph.resize(n+1, list<pp>());//one based indexing
    while(e--){
        int u, v, wt;
        cin >> u >> v >> wt;
        add_edge(u, v, wt);
    }
    int src;
    cout << "Enter the source: ";
    cin >> src;
    cout << "Minimum weigh tree is: " << prims(src, n);
    return 0;
}