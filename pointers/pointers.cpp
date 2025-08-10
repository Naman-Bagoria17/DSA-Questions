#include<bits/stdc++.h>
using namespace std;
void find_occurences(string s,int *x,int *y){
    for(int i=0;i<s.size();i++){
        if(s[i]=='a'){
            *x=i;
            break;
        }
    }
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='a'){
            *y=i;
            break;
        }
    }
}

void print(int *array,int n){//function ke andar pointer paas kiya is pointer ne vo address pkd liya jo function call pe pass kiya
//pass by reference ho raha
    for(int i=0;i<n;i++){
        cout<<*(array+i)<<" ";
    }
    *(array+1)=6565;
}
int main(){
//     //lecture 1 
//     int x=1;
//     int *p1=&x;
//     cout<<&x<<" "<<p1<<endl;
//     cout<<x<<" "<<*p1<<endl;//dereferencing
//     int* random;
//     cout<<random<<endl;//stores random address
// /*computation*/    *p1=5;//updating value using dereferencing
//     cout<<x<<endl;
//     cout<<&p1<<endl;//address of pointer itself

//     //mistakes
//     int y=10;
//     int*p2=&y;
//     int z=4;
//     // p=4;//error
//     // *p=&z;//error(because you're dereferncing the value stored at address stored in p)
//     //in simple language, x is an integer, it can't be an address
    
    // //call by reference using pointers
    // //find first and last occurrence of 'a'
    // string s="aabac";
    // int first=-1;
    // int last=-1;
    // int *pf=&first;
    // int *pl=&last;
    // find_occurences(s,pf,pl);
    // cout<<first<<" "<<last<<endl;
    // cout<<*pf<<" "<<*pl<<endl;

// //pointer arithmetic
// int arr[]={1,5,3,6};
// print(arr,4);//address pass kr diya
// cout<<endl<<*(arr+1)<<endl;
}