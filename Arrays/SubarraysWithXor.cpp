long subarrayXor(vector<int> &arr, int x)
{
    unordered_map<int, int> xorFreq;
    int currXor = 0;
    long ans = 0;

    for (auto ele : arr)
    {
        currXor = currXor ^ ele;
        if (currXor == x)
            ans++;

        if (xorFreq.find(currXor ^ x) != xorFreq.end())
        {
            ans += xorFreq[currXor ^ x];
        }
        xorFreq[currXor]++;
    }

    return ans;
}
