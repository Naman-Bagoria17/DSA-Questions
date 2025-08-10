#include<bits/stdc++.h>
using namespace std;
void Heapify(int* minHeap,int& size,int curr){
    while(curr*2<=size){
        int leftChild = curr * 2;
        int rightChild = curr * 2 + 1;
        int minChild = leftChild;
        if(rightChild<=size and minHeap[rightChild]<minHeap[minChild]){
            minChild = rightChild;
        }
        if(minHeap[minChild]>=minHeap[curr])
            return;
        swap(minHeap[curr], minHeap[minChild]);
        curr = minChild;
    }
}
int main(){
    int minHeap[] = {-1, 60, 10, 80, 50, 5, 20, 70};
    int size = 7;
    for (int i = size / 2; i > 0;i--){
        Heapify(minHeap, size, i);
    }
        for (int i = 1; i <= size; i++)
        {
            cout << minHeap[i] << " ";
        }
    return 0;
}