#include<bits/stdc++.h>
using namespace std;
vector<list<int>> graph;
void add_edge(int src, int des, bool bidirec = true)
{
    graph[src].push_back(des);
    if(bidirec)
        graph[des].push_back(src);
}
void display(){
    for (int i = 0; i < graph.size(); i++){
        cout << i << "-> ";
        for(auto ele:graph[i]){
            cout << ele << " ,";
        }
        cout << endl;
    }
}
int main(){
    int v;
    cin >> v;
    graph.resize(v,list<int> ());
    int e;
    cin >> e;   
    while(e--){
        int src, des;
        cin >> src >> des;
        add_edge(src, des, false);//pass birected or not
    }

    display();
    return 0;
}