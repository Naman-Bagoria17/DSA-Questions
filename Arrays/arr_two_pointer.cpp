#include<bits/stdc++.h>
using namespace std;
void sort_zeroes_ones1(vector<int> &v){
    
    //counting zeroes
    int count_zero=0;
    for(int i=0;i<v.size();i++){
        if(v[i]==0){
            count_zero++;
        }
    }
    //array manipulation
    for(int i=0;i<v.size();i++){
        if(i<count_zero){
            v[i]=0;
        }
        else{
            v[i]=1;
        }
    }

}

void sort_zeroes_ones2(vector<int> &v){
    int left_ptr=0;//jo start se traverse krega
    int right_ptr=v.size()-1;//jo end se traverse krega
    while(left_ptr<right_ptr){//qki jb left aur right pointer equal hojaenge mtlb array sort ho chuka hai qki dono pointer center index pe aagye
        if(v[left_ptr]==1 && v[right_ptr]==0){
            v[left_ptr++]=0;// pehle use krega baad me increment
            v[right_ptr--]=1;
        }
        if(v[left_ptr]==0)
        left_ptr++;
        
        if(v[right_ptr]==1)
        right_ptr--;
        
}
}

void sort_even_odd(vector<int> &v){
    int left_ptr=0;
    int right_ptr=v.size()-1;
    while(left_ptr<right_ptr){
        if(v[left_ptr]%2==1 && v[right_ptr]%2==0){
            swap(v[left_ptr],v[right_ptr]);
            left_ptr++;
            right_ptr--;
        }
        if(v[left_ptr]%2==0){
            left_ptr++;
        }
        if(v[right_ptr]%2==1){
            right_ptr--;
        }
    }
    
}
void sorted_squares(vector<int> &v){
    int left_ptr=0;
    int right_ptr=v.size()-1;
    vector<int> ans;
    while(left_ptr<=right_ptr){
        if(abs(v[left_ptr])<abs(v[right_ptr])){
            ans.push_back(pow(v[right_ptr],2));
            right_ptr--;
        }
        else{
            ans.push_back(pow(v[left_ptr],2));
            left_ptr++;
        }
    }
    reverse(ans.begin(),ans.end());//sort in non descending order
    for(int i=0; i<v.size(); i++){
        cout<<ans[i]<<" ";
    }
}

int main(){
// //sort an array consisting of only zeroes and ones
//     int n;
//     cout<<"enter size of array: ";
//     cin>>n;
//     vector<int> v;
//     cout<<"enter elements in the array :";
//     for(int i=0;i<n;i++){
//         int ele;
//         cin>>ele;
//         v.push_back(ele);
//     }
//     sort_zeroes_ones1(v);
//     //getting ouput
//     for(int i=0;i<n;i++){
//         cout<<v[i]<<"\t";
//     }

// //sort an array consisting of only zeroes and ones
// //BUT TRAVERSING ARRAY ONLY ONCE(two pointers)
//     int n;
//     cout<<"enter size of array: ";
//     cin>>n;
//     vector<int> v;
//     cout<<"enter elements in the array :";
//     for(int i=0;i<n;i++){
//         int ele;
//         cin>>ele;
//         v.push_back(ele);
//     }
//     sort_zeroes_ones2(v);
//     //getting ouput
//     for(int i=0;i<n;i++){
//         cout<<v[i]<<"\t";
//     }

// //move all even integers to the beginning of the array followed by the odd integers
//     int n;
//     cout<<"enter size of array: ";
//     cin>>n;
//     vector<int> v;
//     cout<<"enter elements in the array :";
//     for(int i=0;i<n;i++){
//         int ele;
//         cin>>ele;
//         v.push_back(ele);
//     }
//     sort_even_odd(v);
//     //getting ouput
//     for(int i=0;i<n;i++){
//         cout<<v[i]<<"\t";
//     }

// //Given an array in non decreasing order.
// //print an array of squares of each number in non decreasing order
// //element of array can be negative
//     int n;
//     cout<<"enter size of array: ";
//     cin>>n;
//     vector<int> v;
//     cout<<"enter elements in the array :";
//     for(int i=0;i<n;i++){
//         int ele;
//         cin>>ele;
//         v.push_back(ele);
//     }
//     sorted_squares(v);
    return 0;
}