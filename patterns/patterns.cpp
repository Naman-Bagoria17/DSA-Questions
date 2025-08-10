// #include<iostream>
// using namespace std;
// int prime(int);
// int pattern(int);
// int main(){ 
    // //rectangular pattern
    // int m,n;
    // cout<<"enter rows\t";
    // cin>>m;
    // cout<<"enter columns\t";
    // cin>>n;
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }

    // //hollow rectangular pattern
    // int m,n;
    // cout<<"enter rows\t";
    // cin>>m;
    // cout<<"enter columns\t";
    // cin>>n;
    // for(int i=1;i<=m;i++){
    //     for(int j=1;j<=n;j++){
    //         if(i==1 || j==1 || i==m || j==n){
    //             cout<<"*";
    //         }
    //         else{
    //             cout<<" ";
    //         }
    //     }
    //     cout<<endl;
    // }

    // // triangular pattern
    // int m;
    // cout<<"enter rows\t";
    // cin>>m;
    // for(int i=1;i<=m;i++){
    //     for(int j=1;j<=i;j++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }

    // // reverse triangular pattern
    // int m;
    // cout<<"enter rows\t";
    // cin>>m;
    // for(int i=m;i>=1;i--){
    //     for(int j=1;j<=i;j++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
    
    // //pyramid pattern
    // int m;
    // cout<<"enter rows\t";
    // cin>>m;
    // for(int i=1; i<=m; i++){
    //     for(int j=1;j<=m-i; j++){
    //         cout<<" ";
    //     }
    //     for(int k=1;k<=2*i-1;k++){
    //         cout<<"*";
    //     } 
    //     cout<<endl;
    // }

    // //numerical rectangular pattern
    // int m;
    // cout<<"enter rows\t";
    // cin>>m;
    // for(int i=1; i<=m; i++){
    //     for(int j=i;j<=m;j++){
    //         cout<<j<<" ";
    //     }
    //     for(int k=1;k<=i-1;k++){
    //         cout<<k<<" ";
    //     }
    //     cout<<endl;
    // }

    // // hollow numerical rectangle
    // int m,n;
    // cout<<"enter rows\t";
    // cin>>m;
    // cout<<"enter columns\t";
    // cin>>n;
    // for(int i=1;i<=m;i++){
    //     for(int j=1;j<=n;j++){
    //         if(i==1 || j==1 || i==m || j==n){
    //             cout<<j;
    //         }
    //         else{
    //             cout<<" ";
    //         }
    //     }
    //     cout<<endl;
    // }  
    
    // //pattern:
    // //121212
    // //212121
    // //121212
    // //212121

    // int m,n;
    // cout<<"enter rows\t";
    // cin>>m;
    // cout<<"enter columns\t";
    // cin>>n;
    // for(int i=1; i<=m; i++){
    //     for(int j=1;j<=n;j++){
    //         if((j%2==0)^(i%2==0)){//jb row and column both are even or both are odd then 1 is printed
    //             cout<<"2";
    //         }
    //         else{
    //             cout<<"1";
    //         }
    //     }
    //     cout<<endl;
    // }
    
    // //Numerical triangular pattern
    // int m;
    // cout<<"enter the no of rows\t";
    // cin>>m;
    // for(int i=1; i<=m; i++){
    //     for(int j=1; j<=i; j++){
    //         cout<<j;
    //     }
    //     cout<<endl;
    // }

    // //pattern
    // //    1  
    // //   121
    // //  12321
    // // 1234321
    
    // int m;
    // cout<<"enter the no of rows\t";
    // cin>>m;
    // for(int i=1; i<=m; i++){
    //     for(int j=1;j<=m-i; j++){
    //         cout<<" ";
    //     }
    //     for(int k=1;k<=i;k++){
    //         cout<<k;
    //     }
    //     for(int l=i-1;l>=1;l--){
    //         cout<<l;
    //     }
    //     cout<<endl;
    // }

//     //pattern
//     //    1
//     //   2 2
//     //  3   3
//     // 4444444

//     int m;
//     cout<<"enter the no of rows\t";
//     cin>>m;
//     for(int i=1;i<=m;i++){
//         for(int j=1;j<=m-i;j++){
//             cout<<" ";
//         }
//         for(int k=1;k<=2*i-1;k++){
//          if(i!=m){
//             if(k==1||k==2*i-1){
//                 cout<<i;
//             }
//             else{
//                 cout<<" ";
//             }
//          }
//          else{
//             cout<<i;
//          }
//         }
//         cout<<endl;
//     }

//pattern
//      A
//     ABC
//    ABCDE
//   ABCDEFG
//  ABCDEFGHI//this will be the input (line number)
//   ABCDEFG
//    ABCDE
//     ABC
//      A

// //upper triangle(my way)
// int line;
// cout<<"enter the row number\t";
// cin>>line;
// for(int i=0; i<2*line-1; i++){
//     for(int j=line-i;j>1;j--){
//         cout<<" ";
//     }
//     for(int j=0;j<2*i+1;j++){
//         if(i<line){
//             cout<<char('A'+j);
//         }
//         else{
//             break;
//         }
//     }
//     cout<<endl;

// }

// //upper triangle 2nd method(easy)
// int n;
// cout<<"enter the number of rows\t";
// cin>>n;
// for(int line=1;line<=n;line++){
//     for(int j=n-line;j>=1;j--){
//         cout<<" ";
//     }
//     for(int j=0;j<2*line-1;j++){
//         cout<<char('A'+j);
//     }
//     cout<<endl;
// }
// //lower triangle
// for(int line=n+1;line<=2*n-1;line++){
//     for(int j=1;j<=line-n;j++){
//         cout<<" ";
//     }
//     for(int j=0;j<2*(2*n-line)-1;j++){
//         cout<<char('A'+j);
//     }
//     cout<<endl;
// }

// //pattern(input will always be odd)
// //      *
// //      *
// //  * * * * * 
// //      *
// //      *

// int n;
// cout<<"enter the number of rows\t";
// cin>>n;
// for(int i=1;i<=n;i++){
//     if(i==(n+1)/2){
//         for(int j=1;j<=n;j++){
//             cout<<"* ";
//         }
//     }
//     else{
//         for(int j=1;j<n;j++){
//             cout<<" ";
//         }
//         cout<<"*";
//     }
//     cout<<endl;
// }

// //1234554321
// //1234**4321
// //123****321
// //12******21
// //1********1
// int n;
// cout<<"enter the number of rows\t";
// cin>>n;
// for(int i=n;i>=1;i--){
//     for(int j=1;j<=i;j++){
//         cout<<j;
//     }
//     for(int k=1;k<=2*(n-i+1)-2;k++){
//         cout<<"*";
//     }
//     for(int l=i;l>=1;l--){
//         cout<<l;
//     }
//     cout<<endl;
// }

// // program to print triangle of prime numbers upto given number of rows
// // input rows-4 
// //      2
// //     3 5
// //   7 11 13
// // 17 19 23 29
// int n;
// cout<<"enter the number of rows\t";
// cin>>n;
// int total=0;
// for(int i=1;i<=n;i++){
//     total+=i;
// }
// int k=2;
// for(int i=1;i<=n;i++){
//     for(int j=n-i;j>=1;j--){
//         cout<<" ";
//     }
// }

//     return 0; 
// }
// int prime(int n){   //prototype declared at the top
//     for(int i=2;i<n;i++){
//         if(n%i==0){
//             return false;
//         }
//     }
//     return true;
// }



// // 33333
// // 32223
// // 32123
// // 32223
// // 33333
// // for n=3
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n = 3;
//     int p = n;
//     for (int i = 0; i < 2 * n - 1; i++)
//     {
//         for (int j = 0; j < 2 * n - 1; j++)
//         {
//             if (i==0 || i==2*n-2 || j==0 || j==2*n-2)
//             {
//                 cout << n;
//             }
//             else{
//                 cout<<n - i;
//             }
//         }
//         cout << endl;
//     }
// }
