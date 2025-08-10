// code also on gfg
// explanation if needed on notebook
long long solve(vector<int> &bt)
{
    // code here
    int waiting = 0;
    int currSum = 0;
    sort(bt.begin(), bt.end());
    for (int i = 1; i < bt.size(); i++)
    {
        currSum += bt[i - 1];
        waiting += currSum;
    }
    int avg = waiting / bt.size();
    return avg;
}
