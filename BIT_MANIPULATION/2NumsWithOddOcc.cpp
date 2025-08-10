vector<long long int> twoOddNum(long long int arr[], long long int N)
{
    long long int xorOfN = 0;
    for (long long int i = 0; i < N; i++)
    {
        xorOfN ^= arr[i];
    }
    long long int maskForRsb = xorOfN & -xorOfN;
    long long int n1 = 0;
    long long int n2 = 0;
    for (long long int i = 0; i < N; i++)
    {
        if (maskForRsb & arr[i])
            n1 ^= arr[i];
        else
            n2 ^= arr[i];
    }
    vector<long long int> ans;
    if (n1 > n2)
    {
        ans.push_back(n1);
        ans.push_back(n2);
    }
    else
    {
        ans.push_back(n2);
        ans.push_back(n1);
    }
    return ans;
}
