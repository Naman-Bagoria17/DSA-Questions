#include<bits/stdc++.h>
using namespace std;
int main(){
    int n = 5;
    vector<vector<int>> ans(n);
    for (int i = 0; i < n;i++){
        ans[i].resize(i + 1);
        for (int j = 0; j <= i;j++){
            if(j==0 || j==i){
                ans[i][j] = 1;
            }
            else{
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
        }
    }
    for (int i = 0; i < n;i++){
        for (int j = 0; j <=i;j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}