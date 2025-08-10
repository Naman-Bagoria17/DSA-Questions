#include<bits/stdc++.h>
using namespace std;
vector<int> subsetSums(vector<int> &arr)
{
    int n = arr.size();
    int totalSubsets = 1 << n;
    vector<int> result;

    for (int mask = 0; mask < totalSubsets; ++mask)
    {
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            if (mask & (1 << i))
            {
                sum += arr[i];
            }
        }
        result.push_back(sum);
    }

    return result;
}
