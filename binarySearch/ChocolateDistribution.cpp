#include<bits/stdc++.h>
using namespace std;
bool canDistChoco(vector<int>& v,int mid,int s){
    int studentsReq = 1;
    int currMaxSum = 0;
    for (int i = 0; i < v.size();i++){
        if(v[i]>mid)
        //if kisi box me chocolates zayada hai jitni hume allocate krni thi maximum
            return false;
        else if(currMaxSum + v[i]>mid){
            studentsReq++;
            if(studentsReq>s)
                return false;
            currMaxSum = v[i];//ab naye student ko allocate krna start kro
        }
        else{
            currMaxSum += v[i];//yahi student ko allocate krdo qki mid se exceed ni ho raha maxSum
        }
    }
    return true;//successfully allocated
}
int ChocolateDistribution(vector<int>& boxes,int s){
    sort(boxes.begin(),boxes.end());
    int l = boxes[0];
    int r = 0;
    for(auto el:boxes){
        r += el;
    }
    int ans = -1;
    while(l<=r){
        int mid = l + (r - l) / 2;
        if(canDistChoco(boxes,mid,s)){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return ans;
}
int main(){
    int n;//no of boxes
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n;i++){
        cin >> v[i];
    }
    int s;//students
    cin >> s;
    cout << ChocolateDistribution(v, s)<<endl;
    return 0;
}