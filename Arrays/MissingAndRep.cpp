// EXPLANATION ON NOTEBOOK'
// 1st approach(giving wrong output for last test case on gfg)
vector<int> findTwoElement(vector<int> &arr)
{
    int n = arr.size();
    long long expSum = n * 1LL * (n + 1) / 2;
    long long expSumOfSq = n * 1LL * (n + 1) * (2 * n + 1) / 6;
    long long actSum = 0;
    long long actSumOfSq = 0;
    for (auto ele : arr)
    {
        actSum += ele;
        actSumOfSq += (long long)(ele * ele);
    }
    long long diff = expSum - actSum;//a-b
    long long sum = (expSumOfSq - actSumOfSq) / diff; // (a+b)=(a^2-b^2)/(a-b)
    int m = (diff + sum) / 2;
    int r = m - diff;
    vector<int> ans = {r, m};
    return ans;
}

// 2nd approach
vector<int> findTwoElement(vector<int> &arr)
{
    int n = arr.size();
    int r = -1;
    long long m = n * 1LL * (n + 1) / 2;

    for (int i = 0; i < n; i++)
    {
        int ele = abs(arr[i]);
        if (arr[ele - 1] < 0)
        {
            r = ele;
        }
        else
        {
            m -= ele; // duplicate ke alava saare numbers subtract ho jayenge
            arr[ele - 1] *= -1;
        }
    }

    return {r, m};
}
