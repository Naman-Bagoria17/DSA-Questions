#include<bits/stdc++.h>
using namespace std;
int find(vector<int>& parent,int x){
    return parent[x] = (parent[x] == x) ? x : find(parent,parent[x]);
}
void Union(vector<int> &parent,vector<int> &rank,int a,int b){
    a = find(parent,a);
    b = find(parent, b);
    if(a==b)return;
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
    //n->no. of elements,m->no. of queries
    vector<int> parent(n + 1);//bcz i want one based indexing
    vector<int> rank(n + 1,0);//initially sbka rank=0
    for (int i = 0; i <= n;i++){
        parent[i] = i;
    }
    while (m--)
    {
        string s;
        cin >> s;
        if(s=="union"){
            int x;
            int y;
            cin >> x >> y;
            Union(parent,rank,x, y);
        }
        else{
            int x;
            cin >> x;
            cout << find(parent, x)<<endl;
        }
    }   
}


