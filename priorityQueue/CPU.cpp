#include<bits/stdc++.h>
using namespace std;
int leastInterval(vector<char> v,int Cdown){

    //storing frequency Array
    unordered_map<char, int> m;
    for(auto ele:v){
        m[ele]++;
    }

    //storing frequencies in PQ
    priority_queue<int> pq;
    for(auto e:m){
        pq.push(e.second);
    }

    int totalTime = 0;
    while(!pq.empty()){
        vector<int> temp;
        //looping till 1 time frame
        for (int i = 1; i <= Cdown + 1; i++){
            if(!pq.empty()){
                int freq = pq.top();
                pq.pop();
                if(freq>1){
                    temp.push_back(freq - 1);
                }
            }
            totalTime++;
            if(pq.empty() and temp.empty()){
                return totalTime;
            }
        }
        for(auto t:temp){
            pq.push(t);
        }
    }
    return totalTime;
}
int main(){
    int n, coolDown;
    cin >> n >> coolDown;
    vector<char> tasks(n);
    for(auto& ele:tasks){
        cin >> ele;
    }
    cout << "Least time is: " << leastInterval(tasks,coolDown);
    return 0;
}