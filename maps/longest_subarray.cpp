//given an array of length n
// find the length of the longest subarray with the sum 0

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int max_len = 0;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> v(n);
    int i = 0;
    while(n--){
        cin >> v[i];
        i++;
    }
    int prefix_sum = 0;
    unordered_map<int, int> m;// prefix sum->index upto which the prefix sum is
    for (int i = 0; i < v.size();i++){
        prefix_sum += v[i];
        if(prefix_sum==0){
            //In case our prefix sum becomes zero then 
            //max length would be number of elements from starting to current idx that is i+1
            max_len=max(max_len,i+1);
        }
        auto itr = m.find(prefix_sum);
        if(itr!=m.end()){
            max_len = max(max_len, i - m[prefix_sum]);
        }
        else{
            m[prefix_sum] = i;
        }
    }
    cout << "The maximum length subarray is: " << max_len;

    //TC-O(n)
    //SC-O(n)
}