#include<bits/stdc++.h>
using namespace std;
vector<int> next_greatest(vector<int> v){
    vector<int> ans(v.size(),-1);//here intitializing size is very necessary
    stack<int> s;
    s.push(0); // sbse pehle vaale ka index to aise hi insert krdo
    for (int i = 1; i < v.size();i++)
    {   
        while(!s.empty() && v[i]>v[s.top()]){//next smallest element ke code me bas yaha sign change krna hai 
            ans[s.top()] = v[i];
            s.pop();
        }
        s.push(i);//jb stack ke top pe koi present element se bada element ho ya fir stack empty ho
        //then only you will come out of while loop
    }
    // while(!s.empty()){// this loop is only mandatory if you have not initialised your vector elements with -1
    //     ans[s.top()] = -1;
    //     s.pop();
    // }
    return ans;
}
int main(){
    vector<int> v = {4, 6, 3, 1, 0, 9, 5, 6, 7, 3, 2};
    vector<int> ans;
    ans=next_greatest(v);
    for (int i = 0; i < ans.size();i++){
        cout << ans[i] << " ";
    }
}
