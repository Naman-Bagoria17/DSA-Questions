#include<bits/stdc++.h>
using namespace std;
void Heapify(int* maxHeap,int& size,int curr){
    while(curr*2<=size){
        int leftChild = curr * 2;
        int rightChild = curr * 2 + 1;
        int maxChild = leftChild;
        if(rightChild<=size and maxHeap[rightChild]>maxHeap[maxChild]){
            maxChild = rightChild;
        }
        if(maxHeap[maxChild]<=maxHeap[curr])
            return;
        swap(maxHeap[curr], maxHeap[maxChild]);
        curr = maxChild;
    }
}
void remove(int* maxHeap,int& size){
    //here we have to swap elements bcz we are storing sorted elements at the end of array
    swap(maxHeap[1],maxHeap[size]);
    size--;
    Heapify(maxHeap, size, 1);
}
void heapSort(int* maxHeap,int size){
    //Heapify all parent nodes into maxHeap
    for (int i = size / 2; i >0;i--){//>0 bcz 0 index has -1
        Heapify(maxHeap, size, i);
    }

    //keep deleting elements from maxHeap until size becomes 0
    while(size>0){
        remove(maxHeap, size);
    }
}
int main(){
    int arr[] = {-1, 60, 10, -8, 50, 5, 20, 10};
    int size = 7;
    heapSort(arr, size);
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}