#include<bits/stdc++.h>
using namespace std;
int main(){
    set<int> marks;
    int n, p, q;
    cout << "Enter n,p,q respectively: ";
    cin >> n >> p >> q;
    for (int i = 0; i <= n;i++){
        for (int j = 0; j <= n;j++){
            int correct = i;
            int incorrect = j;
            int unattended = n - i - j;
            if(unattended>=0){
                int score = correct * p + incorrect * q;
                marks.insert(score);
            }
            else{
                break;
            }
        }
    }
    cout << "Marks: ";
    for(auto ele:marks){
        cout << ele << " ";
    }
    cout << endl<< marks.size();
}