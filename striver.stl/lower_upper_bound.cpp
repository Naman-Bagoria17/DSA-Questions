#include<bits/stdc++.h>
using namespace std;
int main(){
    //find first occurence of x in given array, it not exists return -1
    int a[]={1,1,2,3,4,4,7,7,7,9};
    int n=10;
    cout<<"enter element to be found: ";
    int x;
    cin>>x;
    int idx=lower_bound(a,a+10,x)-a;
    if(idx!=10 && a[idx]==x){
        cout<<idx;
    }
    else{
        cout<<"-1";
    }

    // //find last occurence of x in given array, it not exists return -1
    // int a[]={1,1,2,3,4,4,7,7,7,9};
    // int n=10;
    // cout<<"enter element to be found: ";
    // int x;
    // cin>>x;
    // int idx=upper_bound(a,a+10,x)-a;
    // idx--;
    // if(idx>=0 && a[idx]==x){
    //     cout<<idx;
    // }
    // else{
    //     cout<<"-1";
    // }

    // //find largest number smaller than  x in given array, it not exists return -1
    // int a[]={1,1,2,3,4,4,7,7,7,9};
    // int n=10;
    // cout<<"enter element to be found: ";
    // int x;
    // cin>>x;
    // int idx=lower_bound(a,a+10,x)-a;
    // idx--;
    // if(idx>=0){
    //     cout<<a[idx];
    // }
    // else{
    //     cout<<"-1";
    // }

    // //find smallest number greater than  x in given array, it not exists return -1
    // int a[]={1,1,2,3,4,4,7,7,7,9};
    // int n=10;
    // cout<<"enter element to be found: ";
    // int x;
    // cin>>x;
    // int idx=upper_bound(a,a+10,x)-a;
    // if(idx>=0 && idx!=n){
    //     cout<<a[idx];
    // }
    // else{
    //     cout<<"-1";
    // }

    
}