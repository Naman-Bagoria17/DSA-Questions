#include<bits/stdc++.h>
using namespace std;
bool areIdentical(vector<int> &v1,vector<int> &v2,int a,int min,int max){
    int i;
    for (i = a; i < v1.size();i++){
        if(v1[i]<max and v1[i]>min)
            break;
    }
    int j;
    for (j = a; j < v2.size();j++){
        if(v2[j]<max and v2[j]>min)
            break;
    }  
    // Now we may got the index value of elements that lies in given range for v1 and v2

    if(i==v1.size() && j==v2.size())//means no element in given range
    //we are at leaf nodes
        return true;
    
    //if one vector does not have element in the given range
    if(i==v1.size()  || j==v2.size()){
        return false; 
    }

    //check if both elements are equal or not
    if(v1[i]!=v2[j])//if not equal
        return false;
    //if equal check for subtrees
    return areIdentical(v1, v2, a + 1, min, v1[i]) // left subtree
           && areIdentical(v1, v2, a + 1, v1[i], max);//right subtree
}
int main(){
    int n;
    vector<int> v1,v2;
    cin >> n;
    int i = n;
    while(i--){
        int ele;
        cin >> ele;
        v1.push_back(ele);
    }
    int j = n;
    while(j--){
        int ele;
        cin >> ele;
        v2.push_back(ele);
    }
    cout << areIdentical(v1, v2, 0, INT_MIN, INT_MAX);
}