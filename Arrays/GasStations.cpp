#include<bits/stdc++.h>
using namespace std;
//given constraint-you cannot modify the positions of existing gas stations
//This approach is without binary search
//Time complexity is nearly O(n^2) bcz k*n is quadratic in nature
//we have to optimize this binary search
double findSmallestMaxDist(vector<int> &stations, int k) {
    int n = stations.size();
    //initially jo sections hai vohi sectors hai
    //further ek section me sectors bn jayenge
    //means sections will always be n-1
    //in every section there will be sectors of equal length 
    vector<int> howManyPlaced(n - 1, 0);//so if there are n stations means n-1 sections between them
    //and  this array keeps track of how many gas stations are placed in each section.
    //and since there are n stations,there are n-1 sections between them.
    for (int i = 0; i < k;i++){
        // remember that we are solving this question in a way that between every 2 existing stations
        // all sectors are of equal length(chahe jitne bhi sections ho).It means a section is divided
        // into equal length sectors where sectors=no of new stations placed+1

        double maxLengthSector = -1;//this will keep track ki in any section jo bhi
                                       //maximum length ke sectors hai (not sections)
                                       //qki wahi new gas station rakha jayega
        int maxDistSectionIdx = -1;//this will keep track of that section ka index
        for (int j = 0; j < n - 1;j++){
            double diff = stations[j + 1] - stations[j];
            double sectorLength = diff / (howManyPlaced[j] + 1);//this will tell ki ith section me jo 
            //sectors hai,unme ek sector ki length kitni hai
            if(sectorLength>maxLengthSector){
                maxLengthSector = sectorLength;
                maxDistSectionIdx = j;
            }
        }
        howManyPlaced[maxDistSectionIdx]++;//jonse bhi section me maximum length ke sector hai
                                            //waha new gas station rakh do
    }
    //now all new gas stations have been placed
    double ans = -1;
    for (int i = 0; i < n - 1;i++){
        double diff = stations[i + 1] - stations[i];
        double sectorLength = diff / (howManyPlaced[i] + 1);
        ans = max(ans, sectorLength);
    }
    return ans;
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
