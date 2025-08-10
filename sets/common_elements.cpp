//given two vectors.
//find out the common elements between them and return their sum
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v1={1,1,2,3,3,3};
    vector<int> v2 = {5, 6, 7, 5, 2, 3, 6};
    //common elements are 2 and 3
    int ans = 0;
    set<int> s;
    for (auto ele : v1)
    {
        s.insert(ele);
    }
    for (auto ele : v2)
    {
        if (s.find(ele) != s.end()){
            ans += ele;
        }
    }
    cout << "The sum is : " << ans << endl;
}