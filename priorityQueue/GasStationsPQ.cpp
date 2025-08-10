#include<bits/stdc++.h>
using namespace std;
//TC-nlogn+klogn
//Sc-O(n-1) due to priority queue and howMany array
double findSmallestMaxDist(vector<int>& stations,int k){
    int n = stations.size();
    //priority queue will store length of one sector for every section
    vector<int> howMany(n - 1, 0);//keep track of how many stations are placed in every section
    priority_queue<pair<double, int>> pq;
    //nlogn
    for (int i = 0; i < n - 1;i++){
        pq.push({(stations[i + 1] - stations[i]), i});
    }
    //klogn
    for (int gasStations = 1; gasStations <= k;gasStations++){
        auto curr = pq.top();
        pq.pop();
        int secIdx = curr.second;
        howMany[secIdx]++;//bcz top section of priority queue contains sectors with maximum distance between them. so placed new gas station there

        //this is initital section length between stations jo given hai
        double initDiffBtwStations = stations[secIdx + 1] - stations[secIdx];
        
        //this is new sector length(not section) after new station is placed in that section
        double newSectorLength = initDiffBtwStations / (howMany[secIdx] + 1);

        //now push this newSector length so that it can be again maximum sector length
        pq.push({newSectorLength, secIdx});
    }
    return pq.top().first;//as it is the maximum sector length of maximum distance between two gas stations
}

int main(){
    int n;
    cin >> n;
    vector<int> stations;
    while(n--){
        int ele;
        cin >> ele;
        stations.push_back(ele);
    }
    int k;
    cin >> k;
    cout << findSmallestMaxDist(stations, k) << endl;
}