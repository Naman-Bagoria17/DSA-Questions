#include<bits/stdc++.h>
using namespace std;
// TC- O(n!) bcz yaha pe we are doing f(n)=n*f(n-1) waali thing
void permute(string s,int i){
    if(i==s.size()-1){
        //to print in lexographical order copy the string and use sort function on copy and print
        cout << s<<endl;
        return;
    }
    for (int j = i; j <= s.size() - 1;j++){
        swap(s[i], s[j]);
        permute(s, i + 1);
        swap(s[j], s[i]); 
    }
}
int main(){
    string s;
    cout << "Enter the string: ";
    cin >> s;
    permute(s, 0);
}
