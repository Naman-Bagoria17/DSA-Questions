// optimized approach on leetcode
int threeSumClosest(vector<int> &nums, int target)
{
    int ans = INT_MAX;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < nums.size() - 2; i++)
    {

        // skip duplicates for first number of triplet
        if (i > 0 and nums[i] == nums[i - 1])
            continue;
        int t = target - nums[i];
        int l = i + 1;
        int r = nums.size() - 1;

        while (l < r)
        {
            int twoSum = nums[l] + nums[r];
            if (twoSum < t)
            {
                if (ans == INT_MAX)
                    ans = nums[i] + twoSum;
                else
                {
                    cout << ans;
                    if (abs(target - (nums[i] + twoSum)) < abs(target - ans))
                    {
                        ans = nums[i] + twoSum;
                    }
                    cout << ans;
                }
                while (l < r && nums[l] == nums[l + 1])
                    l++;
                l++;
            }
            else if (twoSum > t)
            {
                if (ans == INT_MAX)
                    ans = nums[i] + twoSum;
                else
                {
                    if (abs(target - (nums[i] + twoSum)) < abs(target - ans))
                    {
                        ans = nums[i] + twoSum;
                    }
                }
                while (l < r && nums[r] == nums[r - 1])
                    r--;
                r--;
            }
            else
            {
                ans = nums[i] + twoSum;
                break;
            }
        }
    }
    return ans;
}