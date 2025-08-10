#include<bits/stdc++.h>
using namespace std;
//following code is done by storing elements into stack not indices
//you can also do it using indices
vector<int> PGE(vector<int> v){
    stack<int> s;
    vector<int> ans(v.size(),-1);
    for (int i = 0; i < v.size();i++)
    {
        while(!s.empty() && s.top()<=v[i]){//pop elements from  stack until we find a greater element
            s.pop();
        }
        if(!s.empty()){//means we found the first previous greater element
            ans[i] = s.top();
        }
        s.push(v[i]);//push the current element onto the stack
    }
    return ans;
}
int main(){

   vector<int> v = {4, 6, 3, 1, 0, 9, 5, 6, 7, 3, 2};
    vector<int> ans;
    ans=PGE(v);
    for (int i = 0; i < ans.size();i++){
        cout << ans[i] << " ";
    }

}