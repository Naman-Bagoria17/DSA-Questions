#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,sum=0;
    vector<int> v;
    map<int, int> freq;
    cout << "Enter n: ";
    cin >> n;
    while (n--)
    {
        int ele;
        cin >> ele;
        v.push_back(ele);
    }
    for(auto ele:v){//O(n)
        freq[ele]++;//if key is absent then it gets inserted with value 1 
        //and if it is present then its value gets incremented
    }
    for(auto ele:freq){//O(m)
        if(ele.second>1)
            sum += ele.first;
    }
    cout << "Sum of repetitive elements is: " << sum;

    // TC: O(n+m) where n is the number of elements in the vector and m is number of unique elements
    // SC: O(m)
}