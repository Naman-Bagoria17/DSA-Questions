#include<bits/stdc++.h>
using namespace std;
//first heapify the whole array into minHeap
//then remove k-1 elements and top element of minHeap is kth smallest
//below code is for zero based indexing
//TC-overall O(N)
void Heapify(int* arr,int& size,int curr){
    while(curr*2+1<size){
        int leftChild = curr * 2+1;
        int rightChild = curr * 2 + 2;
        int minChild = leftChild;
        if(rightChild<size and arr[rightChild]<arr[minChild]){
            minChild = rightChild;
        }
        if(arr[minChild]>=arr[curr])
            return;
        swap(arr[curr], arr[minChild]);
        curr = minChild;
    }
}
void remove(int* arr,int& size){
    //here we have to swap elements bcz we are storing sorted elements at the end of array
    arr[0]=arr[size-1];
    size--;
    Heapify(arr, size, 0);
}
int kthSmallest(int *arr,int size,int k){
    //create MinHeap-O(N)
    for (int i = size / 2-1; i >= 0; i--){
        Heapify(arr, size, i);
    }
    //remove k-1 elements-O(k-1(logN)) and n is reducing one by one given k<n therefore 
    //this Time complexity is less than above for creating minHeap
    k -= 1;
    while(k--){
        remove(arr, size);
    }
    return arr[0];
}
int main(){
    int arr[] = {60, 10, 80, 50, 5, 20, 70};
    int size = 7;
    int k;
    cout << "Enter k:";
    cin >> k;
    cout << kthSmallest(arr, size,k);
    return 0;
}