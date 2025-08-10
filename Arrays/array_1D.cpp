#include<iostream>
using namespace std;

int index_of_max(int arr[], int n){
    int index=-1;
    int first=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>=arr[0]){
            arr[0]=arr[i];
            index=i;
        }
    }
    arr[0]=first;
    return index;
}
int SecondMax(int arr[], int n){
    int index=-1;
    int max=INT16_MIN;
    int second_max=INT16_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>=max){
            max=arr[i];
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]>=second_max && arr[i]!=max){
            second_max=arr[i];
        }
    }
    return second_max;
}

void rotate(int arr[],int n){
    for(int i=1;i<n;i++){
        swap(arr[0],arr[i]);
    }
}


int main(){
    // int array[]={1,2,3,4};
    // cout<<sizeof(array)<<endl;
    // cout<<sizeof(array)/sizeof(array[0])<<endl;//gives length of array

    // //for each loop(datatype_of_element element_variable: array_name)
    // for(int ele:array){
    //     cout<<ele<<" "<<endl;
    // }

    // int arr2[5];
    // for(int ele:arr2){//here ele is a different variable where 
    //     cin>>ele;     //element of array is copied in each iteration
    // }
    // for(int ele:arr2){
    //     cout<<ele<<" "<<endl; 
    // }

    // int arr3[5];
    // for(int &ele:arr3){  //allocating different name for the same memory location
    //     cin>>ele;        // ele is pointing towards the location of array elements
    // }
    // for(int ele:arr3){
    //     cout<<ele<<" "<<endl;
    // }

//     //Linear search
//     int arr4[7];
//     cout<<"enter elements: ";
//     for(int &ele:arr4){  
//         cin>>ele;       
//     }
//     int size=sizeof(arr4)/sizeof(arr4[0]);
//     int search;
//     int index=-1;
//     cout<<"enter element to be searched:\n";
//     cin>>search;
//     for(int i=0;i<size;i++){
//         if(arr4[i]==search){
//             index=i;
//             break;
//         }
//     }
//     if(index==-1){
//         cout<<"not found"<<endl;
//     }
//     else{
//         cout<<search<<" found at index "<<index<<endl;

//     }
    
    // //find total number of pairs whose sum is equal to x
    // int arr[]={1,6,19,3,5,7,12,4,2,0};
    // int n=10;
    // int x;
    // cout<<"enter target sum: ";
    // cin>>x;
    // int sum=0;
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         if((arr[i]+arr[j])==x){
    //             sum++;
    //         }
    //     }
    // }
    // cout<<"The total number of pairs whose sum is "<<x<<" are "<<sum;

//     //find total number of triplets whose sum is equal to x
//     int arr[]={1,6,3,5,7,10,4,2,12,0};
//     int n=10;
//     int x;
//     cout<<"enter target sum: ";
//     cin>>x;
//     int triplets=0;
//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//             int m=arr[i]+arr[j];
//             if(m<=x){
//                 for(int k=j+1;k<n;k++){
//                     if((m+arr[k])==x){
//                         triplets++;
//                     }
//                 }
//             }
//         }
//     }
//     cout<<"The total number of triplets with sum "<<x<<" are "<<triplets;

    // // Find unique number in an array where all elements repeat except one 

    // int arr[]={1,4,5,3,4,1,2,4,3,5};
    // int n=10;
    // for(int i=0;i<n;i++){
    //     bool flag=true;
    //     for(int j=0;j<n;j++){
    //          if(i!=j){
    //             if(arr[i]==arr[j]){
    //                 flag=false;
    //             }
    //         }
    //     }
    //     if(flag==true){
    //         cout<<arr[i];
    //     }
    // }

// find the second largest element in an array
    // int arr[]={1,5,16,7,8,16,14};
    // int index_of_largest=index_of_max(arr,7);
    // for(int i=0; i<7; i++){
    //     if(arr[i]==arr[index_of_largest]){
    //         arr[i]=-1;
    //     }
    // }
    // int index_of_SecondLargest=index_of_max(arr,7);
    // cout<<"The second largest element in the given array is "<<arr[index_of_SecondLargest];

// //another way

//     int arr[]={1,5,16,7,8,16,14};
//     cout<<"The second largest element of the given array "<<SecondMax(arr,7);

//Rotate the given array by k steps where k can be greater than size of array too

    int arr[]={1,2,3,4,5};
    int k;
    cout<<"enter number of steps by which array should be rotated: ";
    cin>>k;
    for(int i=1; i<=k; i++){
        rotate(arr,5);
    }
    for(int i=0; i<5; i++){
        cout<<arr[i]<<"\t";
    }

    return 0; 
}