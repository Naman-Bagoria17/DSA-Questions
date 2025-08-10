#include<iostream>
#include<vector>
using namespace std;
int main(){
    // vector<int> v1(5);
    // cout<<v1.size()<<endl;
    // v1.resize(6);
    // cout<<v1.size()<<endl;

    // vector<int> v;
    // int n;
    // cout<<"enter the size of vector:"<<endl;
    // cin>>n;
    // cout<<"size: "<<v.size();
    // cout<<"capacity: "<<v.capacity()<<endl;
    // v.push_back(5);
    // cout<<"size: "<<v.size();
    // cout<<"capacity: "<<v.capacity()<<endl;
    // v.push_back(3);
    // cout<<"size: "<<v.size();
    // cout<<"capacity: "<<v.capacity()<<endl;
    // v.push_back(4);
    // cout<<"size: "<<v.size();
    // cout<<"capacity: "<<v.capacity()<<endl;
    // v.push_back(9);
    // cout<<"size: "<<v.size();
    // cout<<"capacity: "<<v.capacity()<<endl;
    // int new_size;
    // cout<<"enter new size: ";
    // cin>>new_size;
    // v.resize(new_size);
    // cout<<"size: "<<v.size();
    // cout<<"capacity: "<<v.capacity()<<endl;   
    // v.pop_back();
    // cout<<"size: "<<v.size();
    // cout<<"capacity: "<<v.capacity()<<endl;   

    // vector<int> v3;
    // cout<<"enter elements :"<<endl;
    // for(int i=0;i<6;i++){
    //     int ele;
    //     cin>>ele;//we xcan also take input using v3[i] but we need to specify size at the time of initialization
    //     v3.push_back(ele);
    // }
    // for(int i=0;i<v3.size();i++){
    //     cout<<v3[i]<<" ";
    // }
    // cout << endl;
    // v3.insert(v3.begin()+2,8);
    // for(int i=0;i<v3.size();i++){
    //     cout<<v3[i]<<" ";
    // }
    // cout << endl;
    // v3.insert(v3.end()-5,9);
    // for(int i=0;i<v3.size();i++){
    //     cout<<v3[i]<<" ";
    // }
    // cout << endl;

    // v3.erase(v3.begin()+4);
    // for(int i=0;i<v3.size();i++){
    //     cout<<v3[i]<<endl;
    // }
    // v3.erase(v3.end()-3);
    // for(int i=0;i<v3.size();i++){
    //     cout<<v3[i]<<endl;
    // }

    // for(int ele:v3){
    //     cout<<ele<<" ";
    // }
    // cout<<endl;
    // int i=0;
    // while(i<v3.size()){
    //     cout<<v3[i++]<<" ";
    // }
    
//     //last occurence of an element in an array
//     vector<int> vec(6);
//     cout<<"enter the elements: ";
//     for(int i=0;i<vec.size();i++){
//         cin>>vec[i];
//     }
//     int x;
//     cout<<"enter the element to be searched : ";
//     cin>>x;
//     int occurence=-1;
//     for(int i=vec.size()-1;i>=0;i--){
//         if(vec[i]==x){
//             occurence=i;
//             break;
//         }
//     }
//     if(occurence==-1){
//         cout<<"not found";
//     }
//     else{
//         cout<<"last occurence of element at index "<<occurence;
//     }

// //number of occurences of an element in an array;
//     vector<int> vec(6);
//     cout<<"enter the elements: ";
//     for(int i=0;i<vec.size();i++){
//         cin>>vec[i];
//     }
//     int x;
//     cout<<"enter the element to be searched : ";
//     cin>>x;
//     int num=0;
//     for(int i=0;i<vec.size();i++){
//         if(vec[i]==x){
//             num+=1;
//         }
//     }
//     cout<<x<<" appears "<<num<<" times";

// //check if the given array is sorted or not
//     vector<int> vec(6);
//     cout<<"enter the elements: ";
//     for(int i=0;i<vec.size();i++){
//         cin>>vec[i];
//     }
//     bool sort=true;
//     for(int i=1;i<vec.size();i++){
//         if(vec[i]<vec[i-1]){
//             sort=false;
//             break;
//         }
//     }
//     if(sort==false){
//         cout<<"not sorted";
//     }
//     else{
//         cout<<"sorted";
//     }

// //find the diff. between sum of elements at even indices to the sum of elements at odd indices
//     vector<int> vec(6);
//     cout<<"enter the elements: ";
//     for(int i=0;i<vec.size();i++){
//         cin>>vec[i];
//     }
//     int even=0;
//     int odd=0;
//     for(int i=0;i<vec.size();i++){
//         if(i%2==0){
//             even+=vec[i];
//         }
//         else{
//             odd+=vec[i];
//         }
//     }
//     cout<<"desired output: "<<even-odd;

// //Given Q queries check if the given element is present in the array or not
// //value of all elements is less than 10 raise to power 5
//     int n;
//     cout<<"enter size of original array: ";
//     cin>>n;
//     vector<int> v(n);
//     cout<<"enter elements in the original array :";
//     for(int i=0;i<n;i++){
//         cin>>v[i];
//     }
//     const int N= 1e5+10;//10 raise to power 5
//     vector<int> freq(N,0);//size is N and initializing each element to zero
//     for(int i=0;i<n;i++){
//         freq[v[i]]++;
//     }
//     int q;
//     cout<<"Enter the number of queries :";
//     cin>>q;
//     for(int i=1;i<=q;i++){
//         int queryelement;
//         cout<<"Enter query: ";
//         cin>>queryelement;
//         cout<<"Element found "<<freq[queryelement]<<" times"<<endl;
//     }

    return 0;
}

