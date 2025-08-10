//In this approach-> While finding LIS from every index. I have stored that to which jth index I have to jump from ith index such that arr[i]<arr[j] and this order is a part of LIS starting from arr[i].

#include <bits/stdc++.h>
vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n)
{
    vector<int> jump(n, -1);
    vector<int> dp(n, 1);
    for (int i = n - 2; i >= 0; i--)
    {
        int lis = 1;
        int jumpIdx = -1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                int len = dp[j];
                if (1 + len > lis)
                {
                    jumpIdx = j;
                    lis = 1 + len;
                }
            }
        }
        jump[i] = jumpIdx;
        dp[i] = lis;
    }

    int maxi = 0;
    int lcs = 1;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] > lcs)
        {
            maxi = i;
            lcs = dp[i];
        }
    }

    vector<int> ans;
    int i = maxi;
    while (i < n && i != -1)
    {
        ans.push_back(arr[i]);
        i = jump[i];
    }
    return ans;
}
