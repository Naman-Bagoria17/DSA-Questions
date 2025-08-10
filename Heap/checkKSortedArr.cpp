string isKSortedArray(int arr[], int n, int k)
{
    // code here.
    int temp[n];
    for (int i = 0; i < n; ++i)
    {
        temp[i] = arr[i];
    }
    sort(temp, temp + n);
    for (int i = 0; i < n; i++)
    {
        int lb = lower_bound(temp, temp + n, arr[i]) - temp;
        if (abs(lb - i) > k)
            return "No";
    }
    return "Yes";
}
