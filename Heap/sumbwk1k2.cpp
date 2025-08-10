#include<bits/stdc++.h>
using namespace std;
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
int remove(int* arr,int& size){
    int removedEle = arr[0];
    arr[0]=arr[size-1];
    size--;
    Heapify(arr, size, 0);
    return removedEle;
}
int Sumbetweenk1k2smallest(int *arr,int size,int k1,int k2){
    for (int i = size / 2-1; i >= 0; i--){
        Heapify(arr, size, i);
    }
    int ans = 0;
    int removal = k2 - k1 - 1;
    k1 - 1;
    while(k1--){
        remove(arr, size);
    }
    while(removal--){
        ans += remove(arr, size);
    }
    return ans;
}
int main(){
    int arr[] = {60, 10, 80, 50, 5, 20, 70};
    int size = 7;
    int k1, k2;
    cout << "Enter k1 and k2: ";
    cin >> k1 >> k2;
    cout << Sumbetweenk1k2smallest(arr, size,k1,k2);
    return 0;
}