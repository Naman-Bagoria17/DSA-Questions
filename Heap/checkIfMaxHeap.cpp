bool isMaxHeap(int arr[], int n)
{
    // Your code goes here
    int curr = 0;
    while (curr * 2 + 1 < n)
    {
        if (arr[curr] < max(arr[curr * 2 + 1], arr[curr * 2 + 2]))
            return false;
        curr++;
    }
    return true;
}