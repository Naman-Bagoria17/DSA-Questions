#include<bits/stdc++.h>
using namespace std;
void prefix_sum(vector<int> &v){
    for(int i=1;i<v.size();i++){
        v[i]+=v[i-1];//element update ho raha hai and next element me add ho rha hai
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<"\t";
    }
}
void check_partition(vector<int> &v){
    int total_sum=0;
    for(int i=0;i<v.size();i++){
        total_sum+=v[i];
    }
    int prefix_sum=0;
    for(int i=0;i<v.size();i++){
        prefix_sum+=v[i];
        int suffix_sum=total_sum-prefix_sum;
        if(prefix_sum==suffix_sum){        
          cout<<"partition found between "<<i<<" and "<<i+1<<" index"<<endl;    
          cout<<"prefix sum of v["<<i<<"] is equal to suffix sum from v["<<i+1<<"]";
        }    
   }
}
int main(){
    // //given an array, return prefix/running sum in the same array 
    // int n;
    // cout<<"enter size of array: ";
    // cin>>n;
    // vector<int> v;
    // cout<<"enter elements in the array :";
    // for(int i=0;i<n;i++){
    //     int ele;
    //     cin>>ele;
    //     v.push_back(ele);
    // }
    // prefix_sum(v);

    // //check if we can partition the array into two sub arrays with equal sum
    // //OR check if prefix sum of a part of the array is equal to suffix sum of rest of the array
    // int n;
    // cout<<"enter size of array: ";
    // cin>>n;
    // vector<int> v;
    // cout<<"enter elements in the array :";
    // for(int i=0;i<n;i++){
    //     int ele;
    //     cin>>ele;
    //     v.push_back(ele);
    // }
    // check_partition(v);
    
    // //Given an array of size n. answer q queries where you need to print 
    // //the sum of values in given range of indices from l to r (both included)
    // //the value of l and r in queries follow 1-based indexing
    // //hint-take size of array as input
    // //and make vector of size n+1
    // //store your elements from index 1 to n
    // int n;
    // cout<<"enter size of array: ";
    // cin>>n;
    // vector<int> v(n+1,0);
    // for(int i=1;i<=n;i++){
    //     int ele;
    //     cin>>ele;
    //     v[i]=ele;
    // }
    // for(int i=1;i<=n;i++){
    //     v[i]+=v[i-1];
    // }
    // int q;
    // cout<<"enter number of queries: ";
    // cin>>q;
    // while (q--)
    // {   
    //     int l,r;
    //     cout<<"enter l:";
    //     cin>>l;
    //     cout<<"enter r: ";
    //     cin>>r;
    //     int ans=0;
    //     ans=v[r]-v[l-1];
    //     cout<<"the answer is "<<ans<<endl;
    // }

    return 0;   
}
