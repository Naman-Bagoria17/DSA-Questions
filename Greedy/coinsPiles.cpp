// EXPLANATIONON ON NOTEBOOK
// CODE ALSO ON GFG
int minSteps(int A[], int N, int K)
{
    // code here
    sort(A, A + N);
    vector<int> prefSum(N, 0);
    prefSum[0] = A[0];
    for (int i = 1; i < N; i++)
    {
        prefSum[i] = A[i] + prefSum[i - 1];
    }
    int ans = INT_MAX;
    int prev = 0;
    for (int i = 0; i < N; i++)
    {
        int cnt = 1;
        while (i + 1 < N and A[i] == A[i + 1])
        { // handle duplicates mai sidhha last element ke liye nikal lunga
            cnt++;
            i++;
        }
        int MaxShouldBe = A[i] + K;
        int firstProb = upper_bound(A, A + N, MaxShouldBe) - A;
        int ActualSum = prefSum[N - 1] - prefSum[firstProb - 1];
        int ActualSumShouldBeMax = (N - firstProb) * MaxShouldBe;
        int coinsRemovedFromRight = ActualSum - ActualSumShouldBeMax;
        int coinsRemovedFromLeft = prev;
        ans = min(ans, coinsRemovedFromRight + coinsRemovedFromLeft);
        prev += (A[i] * cnt);
    }
    return ans;
}