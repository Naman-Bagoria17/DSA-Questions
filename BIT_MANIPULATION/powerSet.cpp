// BACKTRACKING APPROACH ALSO ON LEETCODE
vector<vector<int>> subsets(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> ans;
    int totalSubsets = 1 << n;
    for (int i = 0; i < totalSubsets; i++)
    {
        vector<int> sub;
        for (int k = 0; k < n; k++)
        {
            if (i & (1 << k))
            {
                sub.push_back(nums[k]);
            }
        }
        ans.push_back(sub);
    }
    return ans;
}
