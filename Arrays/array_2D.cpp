#include<bits/stdc++.h>
using namespace std;
void spiral(int arr[5][7], int m, int n){
    int top=0;
    int bottom=m-1;
    int left=0;
    int right=n-1;
    while(left<right && top<bottom){
        for(int i=left;i<=right;i++){
            cout<<arr[top][i]<<" ";
        }
        top++;
        for(int i=top;i<=bottom;i++){
            cout<<arr[i][right]<<" ";
        }
        right--;
        for(int i=right;i>=left;i--){
            cout<<arr[bottom][i]<<" ";
        }
        bottom--;
        for(int i=bottom;i>=top;i--){
            cout<<arr[i][left]<<" ";
        }
        left++;
    }
    if(left<right){
        for(int i=left;i<=right;i++){
            cout<<arr[top][i]<<" ";
        }
    }
    if(top<bottom){
        for(int i=top;i<=bottom;i++){
            cout<<arr[i][right]<<" ";
        }
    }
}
int main(){
//print the 2d array in the spiral form
int arr[5][7]={{1,2,3,4,5,6,7},
               {8,9,10,11,12,13,14},
               {15,16,17,18,19,20,21},
               {22,23,24,25,26,27,28},
               {29,30,31,32,33,34,35}
          };
int m=5;
int n=7;
spiral(arr,m,n);

} 