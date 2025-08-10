#include<bits/stdc++.h>
using namespace std;
void insertMinHeap(int* minHeap,int& size,int val){
    size++;
    minHeap[size] = val;
    int curr = size;
    while((curr/2>0) and minHeap[curr]<minHeap[curr/2]){
        swap(minHeap[curr], minHeap[curr / 2]);
        curr /= 2;
    }
}
void deleteMinHeap(int* minHeap,int& size){
    int curr = 1;
    minHeap[1] = minHeap[size];
    size--;
    while(curr*2<=size){//looping till curr node has child nodes or curr node is not a leaf node
        int leftChild = 2 * curr;
        int rightChild = 2 * curr + 1;
        int minChild = leftChild;
        if(rightChild<=size and minHeap[rightChild]<minHeap[leftChild]){
            minChild = rightChild;
        }
        //if minimum child node is greater then we return
        if(minHeap[curr]<minHeap[minChild]){
            return;
        }
        swap(minHeap[curr], minHeap[minChild]);//swapping with minimum child
        curr = minChild;
    }
}
void insertMaxHeap(int* maxHeap,int& size,int val){
    size++;
    maxHeap[size] = val;
    int curr = size;
    while((curr/2>0) and maxHeap[curr]>maxHeap[curr/2]){
        swap(maxHeap[curr], maxHeap[curr / 2]);
        curr /= 2;
    }
}
void deleteMaxHeap(int* maxHeap,int& size){
    int curr = 1;
    maxHeap[1] = maxHeap[size];
    size--;
    while(curr*2<=size){//looping till curr node has no child nodes or curr node is a leaf node
        int leftChild = 2 * curr;
        int rightChild = 2 * curr + 1;
        int maxChild = leftChild;
        if(rightChild<=size and maxHeap[rightChild]>maxHeap[leftChild]){
            maxChild = rightChild;
        }
        // if minimum child node is less then we return
        if(maxHeap[curr]>maxHeap[maxChild]){
            return;
        }
        swap(maxHeap[curr], maxHeap[maxChild]);//swapping with maximum child
        curr = maxChild;
    }
}
int main(){
    // int minHeap[] = {-1, 10, 20, 30, 40, 50};
    // int size = 5;
    // int val = 5;
    // insertMinHeap(minHeap, size, val);
    // for (int i = 1; i <= size;i++){
    //     cout << minHeap[i] << " ";
    // }
    // cout << endl;
    // deleteMinHeap(minHeap, size);
    // for (int i = 1; i <= size;i++){
    //     cout << minHeap[i] << " ";
    // }
    // cout << endl;

    int maxHeap[] = {-1, 60, 50, 40, 30, 20, 10, 5};
    int size = 7;
    int val = 100;
    insertMaxHeap(maxHeap, size, val);
    for (int i = 1; i <= size;i++){
        cout << maxHeap[i] << " ";
    }
    cout << endl;
    deleteMaxHeap(maxHeap, size);
    for (int i = 1; i <= size;i++){
        cout << maxHeap[i] << " ";
    }
    cout << endl;
    return 0;
}