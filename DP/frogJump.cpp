// Memoization
vector<int> dp;
int Helper(vector<int> &heights, int i)
{
    if (i >= heights.size() - 1)
    {
        return 0;
    }
    if (dp[i] != -1)
        return dp[i];
    if (i == heights.size() - 2)
    {
        return dp[i] = abs(heights[i] - heights[i + 1]);
    }
    return dp[i] = min(abs(heights[i] - heights[i + 1]) + Helper(heights, i + 1), abs(heights[i] - heights[i + 2]) + Helper(heights, i + 2));
}
int minCost(vector<int> &height)
{
    dp.resize(height.size(), -1);
    return Helper(height, 0);
}