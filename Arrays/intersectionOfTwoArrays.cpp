// MORE EFFICIENT APPROACH ON LEETCODE
bool found(int ele, vector<int> &v)
{
    int l = 0;
    int r = v.size() - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (v[mid] == ele)
        {
            return true;
        }
        if (ele > v[mid])
            l = mid + 1;
        else
            r = mid - 1;
    }
    return false;
}
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    if (n1 > n2)
        return intersection(nums2, nums1);
    sort(nums2.begin(), nums2.end());
    unordered_set<int> s;
    vector<int> ans;
    for (int i = 0; i < n1; i++)
    {
        bool flag = false;
        if (!s.count(nums1[i]))
        {
            if (found(nums1[i], nums2))
                flag = true;
            s.insert(nums1[i]);
        }
        if (flag)
            ans.push_back(nums1[i]);
    }
    return ans;
}