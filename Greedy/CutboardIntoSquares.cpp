int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N)
{
    sort(X.begin(), X.end(), greater<int>());
    sort(Y.begin(), Y.end(), greater<int>());
    int hr = 1;
    int ve = 1;
    int p = 0;
    int q = 0;
    int ans = 0;
    while (p < X.size() and q < Y.size())
    {
        if (X[p] >= Y[q])
        { // vertical cut
            ans += X[p] * hr;
            ve++;
            p++;
        }
        else
        { // horizonatal cut
            ans += Y[q] * ve;
            hr++;
            q++;
        }
    }
    while (p < X.size())
    {
        ans += X[p] * hr;
        p++;
    }
    while (q < Y.size())
    {
        ans += Y[q] * ve;
        q++;
    }
    return ans;
}
