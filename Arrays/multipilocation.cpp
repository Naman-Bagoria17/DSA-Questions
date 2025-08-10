#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}
    };

    vector<vector<int>> B = {
        {7, 8},
        {9, 10},
        {11, 12}
    };
    vector<vector<int>> ans={2,vector<int>(2,0)};
    for (int i = 0; i < 2;i++){
        for (int j = 0; j < 2;j++){
            for (int k = 0; k < 3;k++){
                ans[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    for (int i = 0; i < 2;i++){
        for (int j = 0; j < 2;j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}