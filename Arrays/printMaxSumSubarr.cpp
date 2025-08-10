vector<int> findSubarray(vector<int> &nums)
{
    int n = nums.size();
    long long maxSum = -1;
    long long currentSum = 0;
    int maxStart = -1;
    int maxEnd = -1;
    int currentStart = 0;

    for (int i = 0; i < n; ++i)
    {
        if (nums[i] >= 0)
        {
            currentSum += nums[i];
            if (currentSum >= maxSum)
            {
                maxSum = currentSum;
                maxStart = currentStart;
                maxEnd = i;
            }
        }
        else
        {
            currentSum = 0;
            currentStart = i + 1;
        }
    }

    if (maxStart == -1)
    {
        return {-1};
    }

    return vector<int>(nums.begin() + maxStart, nums.begin() + maxEnd + 1);
}
