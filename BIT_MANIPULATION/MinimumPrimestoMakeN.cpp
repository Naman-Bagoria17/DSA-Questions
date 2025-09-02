#include<bits/stdc++.h>
using namespace std;

vector<int> sieve(int N,int m){
    vector<int> isPrime(N + 1, true);
    vector<int> mPrimes;

    int cnt = 0;
    for (int i = 2; i * i <= N;i++){
        if(isPrime[i]){
            cnt++;
            mPrimes.push_back(i);
            if(cnt==m)
                return mPrimes;

            for (j = i * i; j <= N;j++){
                isPrime[j] = false;
            }
        }
    }
    return mPrimes;
}

int findMinimumPrimes(int i,vector<int> &mPrimes,int N,vector<vector<int>>& dp){
    if(N==0)
        return 0;
    if(i==mPrimes.size())
        return 1e9;
    if(dp[i][N]!=-1)
        return dp[i][N];
    int notTake = findMinimumPrimes(i + 1, mPrimes, N, dp);
    int take = 1e9;
    if(N-mPrimes[i]>=0){
        take=1+findMinimumPrimes(i,mPrimes,N-mPrimes[i],dp);
    }
    return dp[i][N] = min(take, notTake);
}

int minPrimes(int m,int n){
    vector<int> mPrimes = sieve(n, m);
    vector<vector<int>> dp(mPrimes.size(), vector<int>(n + 1, -1));
    return findMinimumPrimes(0, mPrimes, n, dp);
}