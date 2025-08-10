// SEE EXPLANATION ON NOTEBOOK AND CODE ALSO ON GFG

// TOP DOWN
vector<int> mats;
vector<vector<int>> dp;
int f(int i, int j)
{
    if (j == i + 1 or j == i)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
        // mats[i]*mats[k]*mats[j] is the multiplication jo sbse bahar vaali hai aur
        // sbse aakhir me hogi but we know ye to hogi hi, So counting it earlier.
        ans = min(ans, f(i, k) + f(k, j) + (mats[i] * mats[k] * mats[j]));
    }
    return dp[i][j] = ans;
}
int matrixMultiplication(vector<int> &arr)
{
    dp.clear();
    dp.resize(arr.size(), vector<int>(arr.size(), -1));
    mats = arr;
    return f(0, arr.size() - 1);
}

// BOTTOM UP
// SEE EXPLANATION ON NOTEBOOK AND CODE ALSO ON CODE360
// jb bhi aap memoization me dp ek range pe laga rahe ho like from i to j in above case, mostly cases me tabulization me hume ek length leke chlna hoga, which is the length of the range on which we are seeing.
#include <bits/stdc++.h>

vector<vector<int>> dp;
int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    dp.clear();
    dp.resize(N, vector<int>(N, 0));

    //length of the range
    for (int len = 3; len <= N; len++)
    {
        //starting index of the range
        for (int i = 0; i < N - len + 1; i++)
        {
            int j = i + len - 1;//ending index of the range.
            dp[i][j] = INT_MAX;
            //rest code is same as memoization.
            for (int k = i + 1; k <= j - 1; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + (arr[i] * arr[k] * arr[j]));
            }
        }
    }
    return dp[0][N - 1];
}