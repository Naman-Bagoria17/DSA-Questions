// SHORTCUT ON LEETCODE
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int cnt = 0;
    while(n>1){
        cnt += n & 1;//if number is odd then dividing it by 2 will give remainder as 1 and we want 
        //to add that in cnt. So we can directly check that if number is odd or not.
        n = n >> 1; // then divide the number by 2
    }
    if (n == 1) // to check last quotient
        cnt++;
    cout << cnt << endl;
    return 0;
}