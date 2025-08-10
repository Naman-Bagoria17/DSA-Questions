// STRIVER'S APPROACH
// simple merge sort approach.
// our task would have been easy if we were given two sorted arrays and left element would have
// been from first array and right element from second array. if any second array element is smaller than lets say first array's ith element then it will also be smaller than all elements on the right side of ith element. So while merging the array we can count the inversions when we are putting elements in the auxilliary array!
int cnt = 0;
void merge(vector<int> &nums, int l, int mid, int r)
{
    vector<int> temp;
    int i = l;
    int j = mid + 1;
    while (i <= mid and j <= r)
    {
        if (nums[i] <= nums[j])
        {
            temp.push_back(nums[i]);
            i++;
        }
        else if (nums[i] > nums[j])
        {
            cnt += mid - i + 1;
            temp.push_back(nums[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(nums[i]);
        i++;
    }

    while (j <= r)
    {
        temp.push_back(nums[j]);
        j++;
    }

    for (int k = l; k <= r; k++)
    {
        nums[k] = temp[k - l];
    }
}
void mergeSort(vector<int> &nums, int l, int r)
{
    if (l >= r)
        return;
    int mid = l + (r - l) / 2;
    mergeSort(nums, l, mid);
    mergeSort(nums, mid + 1, r);
    merge(nums, l, mid, r);
}
int inversionCount(vector<int> &arr)
{
    // Your Code Here
    mergeSort(arr, 0, arr.size() - 1);
    return cnt;
}
