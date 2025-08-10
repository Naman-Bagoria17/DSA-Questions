// bubble sort
#include <bits/stdc++.h>
// using namespace std;
// void bubble_sort(int *arr,int n){
//     for (int i = 0; i < n - 1;i++){//no of passes are 0,1,2,3 i.e. [0,n-1)
//         for (int j = 0; j < n - i - 1;j++){//for the first time hme 4 comparison krna hai for j=0,j=1,j=2,j=3 i.e.j jb tk n-i-1 se chhota hai;(n=5 let)
//             if(arr[j]>arr[j+1])
//                 swap(arr[j], arr[j + 1]);
//         }
//     }
// }
// int main(){
//     int arr[] = {20, 50, 30, 10, 40};
//     int n = 5;
//     bubble_sort(arr, n);
//     for (int i = 0; i < n;i++){
//         cout << arr[i] << " ";
//     }
// }

// //optimized bubble sort
// #include<bits/stdc++.h>
// using namespace std;
// void bubble_sort(int *arr,int n){
//     for (int i = 0; i < n - 1;i++){//no of passes are 0,1,2,3 i.e. [0,n-1)
//         bool flag = true;
//         for (int j = 0; j < n - i - 1;j++){//for the first time hme 4 comparison krna hai for j=0,j=1,j=2,j=3 i.e.j jb tk n-i-1 se chhota hai;(n=5 let)
//             if(arr[j]>arr[j+1]){
//                 flag = false;
//                 swap(arr[j], arr[j + 1]);
//             }
//         }
//         if(flag==true)
//             break;//means agr pure pass me koi swapping ni hui mtlb flag abhi bhi true hai to array sorted hai
//     }
// }
// int main(){
//     int arr[] = {10, 20, 40, 30, 50};
//     int n = 5;
//     bubble_sort(arr, n);
//     for (int i = 0; i < n;i++){
//         cout << arr[i] << " ";
//     }
// }

// // selection sort
// #include<bits/stdc++.h>
// using namespace std;
// void selection_sort(int *arr,int n){
//     for (int i = 0; i < n - 1;i++){//no of swaps
//         int min_idx=i;
//         for (int j = i + 1; j < n;j++){//comparing with every element in unsorted part of array
//             if(arr[j]<arr[min_idx]){
//                 min_idx = j;
//             }
//         }
//         if(min_idx!=i){
//             swap(arr[i], arr[min_idx]);
//         }
//     }
// }
// int main(){
//     int arr[] = {5, 8, 4, 9, 2};
//     int n = 5;
//     selection_sort(arr, n);
//     for (int i = 0; i < n;i++){
//         cout << arr[i] << " ";
//     }
// }

// //Insertion sort
// #include<bits/stdc++.h>
// using namespace std;
// void insertion_sort(int arr[],int n){
//     for (int i = 1; i < n; i++){
//         int j = i - 1;
//         int ele = arr[i];
//         while(j>=0 && arr[j]>ele){//yaha pe ele se compare krenge qki arr[i] to change hojayega jb element aage shift honge
//             arr[j + 1] = arr[j];//ek ek step se aage move krna
//             j--;
//         }
//         arr[j + 1] = ele;//qki ab j us position pe hai jo element arr[i] se chhota hai to uske next me insert krdenge arr[i]
//     }
// }
// int main(){
//     int arr[] = {5, 8, 4, 9, 2};
//     int n = 5;
//     insertion_sort(arr, n);
//     for (int i = 0; i < n;i++){
//         cout << arr[i] << " ";
//     }
// }

// //move all zeroes to the end of array while maintainig order of non zero elements
// #include<bits/stdc++.h>
// using namespace std;
// void move_zeroes(int *arr,int n){
//     for (int i = 1; i < n;i++){
//         int ele = arr[i];
//         int j = i - 1;
//         while(j>=0 && arr[j]==0){//jb tk piche continuity me zero hai tb tk loop chlega
//         //bcz humne 1st element se start kiya hai to aage vaale elements ke liye unse pichhe jitne bhi zeroes hai vo ek saath hi honge
//             arr[j + 1] = arr[j];//hum yaha zeroes ko aage shift kr rahe hai
//             j--;
//         }
//         //ye loop se bahar aana mtlb yaha hume humara pehla non zero element mil gya
//         arr[j+1] = ele;//to uske next me humara abhi vaala element daal do
//     }
// }
// int main(){
//     int arr[] = {4,0,3,0,5};
//     int n = 5;
//     move_zeroes(arr, n);
//     for (int i = 0; i < n;i++){
//         cout << arr[i] << " ";
//     }
// }

// //sort fruit names in lexographical order
// #include<bits/stdc++.h>
// using namespace std;
// void sort_fruits(char fruits[][60],int n){
//     for (int i = 0; i < n;i++){
//         int min_idx = i;
//         for (int j = i + 1; j < n;j++){
//             if(strcmp(fruits[j],fruits[min_idx])<0){//strcmp function compares characters of the strings.
//                                                     // it returns 0 if they are equal. positive if 1st one is greater than second and vice versa
//                 min_idx = j;
//             }
//         }
//         if(i!=min_idx){
//             swap(fruits[i], fruits[min_idx]);
//         }
//     }
// }
// int main(){
//     char fruits[][60] = {"pineapple","papaya", "apple", "mango", "banana", "kiwi", "orange", "cherry","pear"};
//     int n = sizeof(fruits) / sizeof(fruits[0]);
//     sort_fruits(fruits, n);
//     for (int i = 0; i < n;i++){
//         cout << fruits[i] << " ";
//     }
// }

// //merge sort
// #include<bits/stdc++.h>
// using namespace std;
// void merge(int *arr,int l,int mid,int r){
//     int a[mid - l + 1];
//     int b[r - mid];
//     for (int i = 0; i < mid - l + 1;i++){
//         a[i] = arr[l + i];
//     }
//     for (int i = 0; i < r - mid;i++){
//         b[i] = arr[mid + 1 + i];
//     }
//     int i = 0, j = 0, k = l;//important
//     while(i<mid-l+1 && j<r-mid){
//         if(a[i]<=b[j]){
//             arr[k++] = a[i++];
//         }
//         else{
//             arr[k++] = b[j++];
//         }
//     }
//     //ho skta hai sirf ek array pura traverse ho jaye aur hm loop se bahar aa jaye
//     while(i<mid-l+1){
//         arr[k++] = a[i++];
//     }
//     while(j<r-mid){
//         arr[k++] = b[j++];
//     }
// }
// void merge_sort(int *arr,int l,int r){
//     if(l>=r)
//         return;
//     int mid = (l + r) / 2;
//     merge_sort(arr, l, mid);
//     merge_sort(arr, mid+1, r);
//     merge(arr, l, mid, r);//l se mid tk ko aur mid se r tk ko ek array me merge krdo
// }
// int main(){
//     int arr[] = {9, 2, 6, 4, 7, 3, 8, 1};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     merge_sort(arr, 0, n - 1);
//     for (int i = 0; i < n;i++){
//         cout << arr[i] << " ";
//     }
// }

// //quick sort
// #include<bits/stdc++.h>
// using namespace std;
// int partition(int *arr,int first,int last){
//     int pivot = last;
//     int i = first - 1;
//     for (int j = first; j <= last - 1;j++){
//         if(arr[j]<arr[pivot]){
//             i++;
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[i + 1], arr[pivot]);
//     return i + 1;//index of pivot element at present
// }
// void quick_sort(int *arr,int first,int last){
//     if (first >= last)
//         return;
//     int pi = partition(arr, first, last);
//     quick_sort(arr, first, pi - 1);
//     quick_sort(arr, pi+1, last);
// }
// int main(){
//     int arr[] = {18,12,30,20,16,35,20};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     quick_sort(arr, 0, n - 1);
//     for (int i = 0; i < n;i++){
//         cout << arr[i] << " ";
//     }
// }

// // COUNT SORT
// #include <bits/stdc++.h>
// using namespace std;
// int max_ele(int arr[], int n)
// {
//     int max = arr[0];
//     for (int i = 1; i < n; i++)
//     {
//         if (arr[i] > max)
//         {
//             max = arr[i];
//         }
//     }
//     return max;
// }
// void count_sort(int *arr, int n)
// {
//     int max = max_ele(arr, n);
//     int freq[max + 1] = {0};
//     for (int i = 0; i < n; i++)
//     {
//         freq[arr[i]]++;
//     }
//     for (int i = 1; i <= max; i++)
//     {
//         freq[i] += freq[i - 1];
//     }
//     int ans[n];
//     for (int i = n - 1; i >= 0; i--)
//     {
//         ans[--freq[arr[i]]] = arr[i];
//     }
//     for (int i = 0; i < n; i++)
//     {
//         arr[i] = ans[i];
//     }
// }
// int main()
// {
//     int arr[] = {1,1,5,2,5};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     count_sort(arr, n);
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
// }

// //radix sort
// #include<bits/stdc++.h>
// using namespace std;
// int max_ele(int arr[],int n){
//     int max = arr[0];
//     for (int i = 1; i < n;i++){
//         if (arr[i]>max){
//             max = arr[i];
//         }
//     }
//     return max;
// }
// void count_sort(int *arr,int n,int pos){
//     int freq[10] = {0};
//     for (int i = 0; i < n;i++){
//         freq[(arr[i]/pos)%10]++;
//     }
//     for (int i = 1; i <=9;i++){
//         freq[i] += freq[i - 1];
//     }
//     int ans[n];
//     for (int i = n - 1; i >= 0;i--){
//         ans[--freq[(arr[i]/pos)%10]] = arr[i];
//     }
//     for (int i = 0; i < n;i++){
//         arr[i] = ans[i];
//     }
// }
// void radix_sort(int *arr,int n){
//     int max = max_ele(arr, n);
//     for (int pos = 1; (max / pos)>0;pos*=10){
//         count_sort(arr, n, pos);
//     }
// }
// int main(){
//     int arr[] = {1090,2,34,56,456,34,324,344};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     radix_sort(arr, n);
//     for (int i = 0; i < n;i++){
//         cout << arr[i]<<" ";
//     }
// }

// //Bucket sort
// #include<bits/stdc++.h>
// using namespace std;
// void bucket_sort(float *arr,int n){
//     //because hume ni pata ek bucket me arr ke kitne elements honge so we can create
//     //either vector of vectors OR array of vectors
//     vector<vector<float>> bucket(n, vector<float>());

//     //putting elements into the bucket
//     for (int i = 0; i < n;i++){
//         int index = arr[i] * n;
//         bucket[index].push_back(arr[i]);
//     }

//     //sorting individual buckets
//     for (int i = 0; i < n;i++){
//         if(!bucket[i].empty()){
//             sort(bucket[i].begin(), bucket[i].end());
//         }
//     }

//     //combining elements from every bucket
//     int k = 0;
//     for (int i = 0; i < n;i++){
//         for (int j = 0; j < bucket[i].size();j++){
//             arr[k++] = bucket[i][j];
//         }
//     }
// }
// int main(){
//     float arr[] = {0.13,0.452,0.12,0.892,0.751,0.63,0.85,0.895,0.45};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     bucket_sort(arr, n);
//     for (int i = 0; i < n;i++){
//         cout << arr[i]<<" ";
//     }
// }

// //if elements are more than 1
// //Bucket sort
// #include<bits/stdc++.h>
// using namespace std;
// void bucket_sort(float *arr,int n){
//     vector<vector<float>> bucket(n, vector<float>());
//     float max_ele = arr[0];
//     float min_ele = arr[0];
//     for (int i = 1; i < n;i++){
//         max_ele = max(max_ele, arr[i]);
//         min_ele = min(min_ele, arr[i]);
//     }
//     float range = (max_ele - min_ele) / n;
//     for (int i = 0; i < n; i++){
//             int index = (arr[i]-min_ele)/range;
//             //if element is a boundary(max) element then index will be equal to size of array
//             float diff = (arr[i] - min_ele) / range - index;//if index is equal to its float form
//             //basically if 8.0==8 then diff is 0.
//             if(diff==0 && arr[i]!=min_ele){//for last element
//                 bucket[index-1].push_back(arr[i]);
//             }
//             else
//             bucket[index].push_back(arr[i]);
//     }
//     for (int i = 0; i < n;i++){
//         if(!bucket[i].empty()){
//             sort(bucket[i].begin(), bucket[i].end());
//         }
//     }
//     int k = 0;
//     for (int i = 0; i < n;i++){
//         for (int j = 0; j < bucket[i].size();j++){
//             arr[k++] = bucket[i][j];
//         }
//     }
// }
// int main(){
//     float arr[] = {6.13,8.452,0.12,1.892,4.751,2.63,7.85,1.895,10.45};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     bucket_sort(arr, n);
//     for (int i = 0; i < n;i++){
//         cout << arr[i]<<" ";
//     }
// }
