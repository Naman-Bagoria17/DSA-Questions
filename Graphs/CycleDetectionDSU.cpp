#include<bits/stdc++.h>
using namespace std;
int find(vector<int> parent,int x){
    return parent[x] = (parent[x] == x) ? x : find(parent,parent[x]);
}
bool Union(vector<int> &parent,vector<int> &rank,int a,int b){
    a = find(parent,a);
    b = find(parent, b);
    if(a==b)
        return true;
    if (rank[a] >= rank[b]){
        rank[a]++;
        parent[b] = a;
    }
    else{
        rank[b]++;
        parent[a] = b;
    }
}
int main(){
    int m, n;
    cin >> n >> m;
    //n->no. of elements,m->no. of queries/egdes
    vector<int> parent(n + 1);//bcz i want one based indexing
    vector<int> rank(n + 1,0);//initially sbka rank=0
    for (int i = 0; i <= n;i++){
        parent[i] = i;
    }
    while (m--)
    {
        int x;
        int y;
        cin >> x >> y;
        if(Union(parent,rank,x, y)==true){
            cout<<"Cycle exists!!";
            exit(0);
        }
    } 
    if(m==-1){
        cout << "cycle does not exists!!";
    }  
}