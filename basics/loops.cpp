#include<iostream>
using namespace std;
int main(){
    // int sum=0;
    // int n;
    // cout<<"enter the natural number upto which you wish to find the sum\t";
    // cin>>n;
    // int i=1;
    // while(i<n+1){
    //     sum+=i;
    //     i++;
    // }
    // cout<<"the sum is "<<sum<<endl;

    // //using for loop
    // for(int i=0;i<n+1;i++){
    //     sum+=i;
    // }
    // cout<<"the sum is "<<sum<<endl;

    // //print the first multiple of 5 which is also a multiple of 7
    // int i=5;
    // while(true){
    //     if(i%7==0){
    //         cout<<i<<endl;
    //         break;
    //     }
    //     i+=5;
    // }
    
    //Do while loop
    // //print the sum of the stream of n integers in the input using do while loop
    // int n;
    // cout<<"enter the no. of integers\t";
    // cin>>n;
    // int sum=0;
    // do{
    //     int num;
    //     cin>>num;
    //     sum+=num;
    //     n--;
    // }while(n>0);//
    // cout<<"the sum is "<<sum<<endl; 

    // //print values between 1 and 50 except for multiples of 3
    // int i=1;
    // do{
    //    if(i%3!=0){
    //     cout<<i;
    //    }
    //    i++;
    // }while(i<50);
    
    // //count the no. of digits for a given no.
    // int number;
    // cout<<"enter the number\t";
    // cin>>number;
    // int digits=0;
    // while(number>0){
    //     digits++;
    //     number/=10;
    // }
    // cout<<"number of digits are "<<digits;

    // //count the sum of digits for a given no.
    // int number;
    // cout<<"enter the number\t";
    // cin>>number;
    // int sum=0;
    // while(number>0){
    //     int rem=number%10;
    //     sum+=rem;
    //     number/=10;
    // }
    // cout<<"the sum of digits is "<<sum;

    // //reverse the digits of a number
    // int number;
    // cout<<"enter the number\t";
    // cin>>number;
    // int reverse=0;
    // while(number>0){
    //    int rem=number%10;
    //    reverse=reverse*10+rem;
    //    number/=10;
    // }
    // cout<<"the reverse of number is "<<reverse;

    // //find the sum of the following series
    // // 1-2+3-4+......n
    // int number;
    // cout<<"enter the number\t";
    // cin>>number;
    // int sum=1;
    // for(int i=2;i<=number;i++){
    //     if(i%2==0){
    //         sum-=i;
    //     }
    //     else{
    //         sum+=i;
    //     }
    // }
    // cout<<"the sum of the series is "<<sum;

    // //print the first n factorial numbers
    // int n;
    // cout<<"enter the number\t";
    // cin>>n;
    // int fact=1;
    // for(int i=1;i<=n;i++){
    //     fact*=i;
    //     cout<<fact<<endl;
    // }

    // //find a raise to the power b
    // int a;
    // cout<<"enter the base\t";
    // cin>>a;
    // int b;
    // cout<<"enter the exponent\t";
    // cin>>b;
    // int result=1;
    // for(int i=1;i<=b;i++){
    //     result*=a;
    // }
    // cout<<result;

    // //convert binary to decimal
    // int n;
    // cout<<"enter the binary number: ";
    // cin>>n;
    // int ans=0;
    // int power=1;
    // while(n>0){
    //     int lastdigit=n%10;
    //     ans += lastdigit*power;
    //     power *= 2;
    //     n/=10;
    // }
    // cout<<ans;

    // //convert decimal to binary
    // int n;
    // cout<<"enter the decimal number: ";
    // cin>>n;
    // int ans=0;
    // int power=1;
    // while(n>0){
    //     int paritydigit=n%2;
    //     ans += paritydigit*power;
    //     power *= 10;
    //     n/=2;
    // }
    // cout<<ans;

    return 0;
}