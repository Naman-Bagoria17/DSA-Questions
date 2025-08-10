#include <bits/stdc++.h>
void heapify(long *arr, int n, int i)
{
    int curr = i;
    while (curr * 2 + 1 < n)
    {
        int left = curr * 2 + 1;
        int right = curr * 2 + 2;
        int maxChild = left;
        if (right < n && arr[right] > arr[left])
            maxChild = right;
        if (arr[curr] > arr[maxChild])
            break;
        swap(arr[curr], arr[maxChild]);
        curr = maxChild;
    }
}
void minHeapToMaxHeap(long *arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}