// This approach uses a hashmap therefore is less optimal
// I have done using only pointers on Leetcode
int numSubarraysWithSum(vector<int> &nums, int goal)
{
    int currSum = 0;
    int ans = 0;
    unordered_map<int, int> m;
    m[0]++;
    for (int i = 0; i < nums.size(); i++)
    {
        currSum += nums[i];
        ans += m[currSum - goal];
        m[currSum]++;
    }
    return ans;
}
