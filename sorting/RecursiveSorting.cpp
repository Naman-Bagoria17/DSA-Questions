#include <bits/stdc++.h>
using namespace std;
// // RECURSIVE BUBBLE SORT

// void bubbleSort(vector<int> &arr,int n)
// {
//     if (n == 1)
//         return;
//     bool swapped = false;
//     for (int j = 1; j < n; j++)
//     {
//         if (arr[j] < arr[j - 1])
//         {
//             swap(arr[j], arr[j - 1]);
//             swapped = true;
//         }
//     }
//     if (!swapped)
//         return;
//     else
//         bubbleSort(arr, n-1);
// }

// int main()
// {
//     vector<int> arr = {1, 5, 4, 3, 2};
//     bubbleSort(arr, arr.size());
//     for(auto ele:arr){
//         cout << ele << " ";
//     }
//     cout << endl;
//     return 0;
// }

// RECURSIVE INSERTION SORT
void insertionSort(vector<int> &arr, int i)
{
    if (i == arr.size())
        return;
    int ele = arr[i];
    int j = i - 1;
    while (j > -1 and arr[j] > ele)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = ele;
    insertionSort(arr, i + 1);
}

int main()
{
    vector<int> arr = {1, 5, 4, 3, 2};
    insertionSort(arr, 0);
    for(auto ele:arr){
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}
