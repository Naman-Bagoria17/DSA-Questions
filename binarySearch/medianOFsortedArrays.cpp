class Solution
{
    // This is brute force TC=O(m+n)=SC
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int i = 0, j = 0;
        vector<int> merged;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] <= nums2[j])
            {
                merged.push_back(nums1[i]);
                i++;
            }
            else
            {
                merged.push_back(nums2[j]);
                j++;
            }
        }
        while (i < nums1.size())
        {
            merged.push_back(nums1[i]);
            i++;
        }
        while (j < nums2.size())
        {
            merged.push_back(nums2[j]);
            j++;
        }
        if (merged.size() % 2 == 0)
        {
            double median = double(merged[(merged.size() / 2) - 1] + merged[(merged.size() / 2)]) / 2;
            return median;
        }
        else
        {
            double median = merged[merged.size() / 2];
            return median;
        }
    }
};