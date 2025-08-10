// Works for both positives and negatives
int longestSubarray(vector<int> &arr, int k)
{
    int n = arr.size();
    if (n == 1)
        return arr[0] == k;
    unordered_map<int, int> prefixSum;
    int maxLen = 0;
    int currSum = 0;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        if (currSum == k)
        {
            maxLen = i + 1;
        }
        if (prefixSum.find(currSum - k) != prefixSum.end())
        {
            maxLen = max(maxLen, i - prefixSum[currSum - k]);
        }
        if (prefixSum.find(currSum) == prefixSum.end())
            prefixSum[currSum] = i;
    }
    return maxLen;
}
