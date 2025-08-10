#include<bits/stdc++.h>
using namespace std;
bool isPossible(unordered_map<char,int>& freq){
    int cnt = 0;
    for(auto ele:freq){
        if(freq[ele.first]%2!=0){
            cnt++;
            if(cnt>1)
                return false;
        }
    }
    return true;
}
string largestPal(string s){
    int l = s.size();
    unordered_map<char, int> freq;
    for (int i = 0; i < l;i++){
        freq[s[i]]++;
    }
    if(!isPossible(freq))
        return "Not Possible";
    vector<char> v(l);
    int front = 0;
    for (char i = '9'; i >= '0';i--)
    {
        if(freq[i]%2!=0){
            v[l / 2] = i;
            freq[i]--;
        }
        while(freq[i]>0){
            v[front] = i;
            v[l - front - 1] = i;
            freq[i] -= 2;
            front++;
        }
    }
    string res = "";
    for (int i = 0; i < v.size();i++){
        res += v[i];
    }
    return res;
}
int main(){
    string s;
    cin >> s;
    cout << largestPal(s);
    return 0;
}