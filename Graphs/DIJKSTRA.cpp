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
//pq-distance to reach that node and the node itself.
void dijkstra(int src,int n){//O(VlogV+ElogV)
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    unordered_set<int> vis;
    vector<int> via(n);// to store via which node we reached that node
    map<int, int> m;//storing node---minimum distance till now 
    for (int i = 1; i <= n; i++){//bcz of one based indexing
        m[i] = INT_MAX;//O(V)
    }
    pq.push({0, src});
    m[src] = 0;
    via[src] = -1;
    while(!pq.empty()){//O((V+E)logV)
    //where V+E is for below for loop for bfs traversing of whole graph
    //and we are assuming priority queue me har
    //element ek baar ya do baar add ho hi raha hai. thus logV for that
        auto curr = pq.top();
        pq.pop();
        vis.insert(curr.second); // jaise hi queue se bahar nikla mark it visited
        for (auto neighbour : graph[curr.second]){
            if (!vis.count(neighbour.first) /*visited set will also help ki koi bhi apne parent pe na jaye*/
                    and m[neighbour.first] > m[curr.second]/*curr node tk ka shortest path*/ + neighbour.second)
            { // we found a better edge
                pq.push({m[curr.second] + neighbour.second, neighbour.first});
                via[neighbour.first] = curr.second;
                m[neighbour.first] = m[curr.second] + neighbour.second;
            }
        }
    }
    int i = 1;
    cout << "Node" << setw(10) << "MinDist" << setw(10) << "via" << endl;
    for(auto ele: m){
        cout << ele.first << setw(10) << ele.second << setw(10) << via[i] << endl;
        i++;
    }
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
    dijkstra(src, n);
    return 0;
}

