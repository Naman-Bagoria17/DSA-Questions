#include<iostream>
#include<cmath> //math.h
using namespace std;
//some inbuilt functions

// int main(){
//     cout<<pow(2,10)<<endl;
//     cout<<sqrt(169)<<endl;
//     cout<<sqrt(343)<<endl;//prints double type value by default
//     int int_sqrt= sqrt(343);
//     double double_sqrt= sqrt(343);
//     cout<<int_sqrt<<endl;
//     cout<<double_sqrt<<endl;
//     return 0;
// }

// int add(int a, int b){
//     int result= a+b;
//     return result;
// }
// int print(string name){
//     cout<<"hello "<<name<<endl;
// }
// int main(){
//     print("naman");
//     int result=add(4,5);
//     cout<<result;
//     return 0;
// }

// //function to print squares of first n natural numbers

// int square_numbers(int x){
//     return x*x;
// }
// int main(){
//     int n;
//     cout<<"Enter n: ";
//     cin>>n;
//     for(int i=1;i<=n;i++){
//         cout<<square_numbers(i)<<endl;
//     }
//     return 0;
// }

// // //given radius, calculate area and circumference of circle

// int square_numbers(int x){
//     return x*x;
// }
// float area(float r){
//     return 3.14*square_numbers(r);
// }
// float circumference(float r){
//     return 3.14*2*r;
// }
// int main(){
//     float radius;
//     cout<<"Enter radius: ";
//     cin>>radius;
//     cout<<"Area: "<<area(radius)<<endl;
//     cout<<"Circumference: "<<circumference(radius);
//     return 0;
// }

// //check the person is eligible to vote or not
// bool check(int age, int limit){
//     if(age>=limit){
//         return true;
//     }
//     else{
//         return false;
//     }
// }
// int main(){
//     int age_limit;
//     cout<<"enter age limit: ";
//     cin>>age_limit;
//     int age;
//     cout<<"enter age: ";
//     cin>>age;
//     if(check(age,age_limit)==true){
//         cout<<"you are eligible to vote"<<endl;
//     }
//     else{
//         cout<<"not eligible to vote";
//     }
//    return 0;
// }

// //given two numbers, print all odd numbers between them

// void print_odd(int a,int b){
//     for(int i=a;i<=b;i++){
//         if(i%2!=0){
//             cout<<i<<endl;
//         }
//         else{
//             continue;
//         }
//     }
// }
// int main(){
//     int a,b;
//     cout<<"enter lower limit: ";
//     cin>>a;
//     cout<<"enter upper limit: ";
//     cin>>b;
//     print_odd(a,b);
//     return 0;
// }

// //given two numbers, print all prime numbers between them

// bool is_Prime(int n){
//         for(int i=2;i<n;i++){ 

// // here we are checking from 2 to n that 
// // if n is divisible by any number or not.
// // if we have a higher value of b then we have
// // to go through so many iterations so instead
// // of checking upto n we can check upto sqrt(n)
// // like i<=sqrt(n) or i*i<=n because after sqrt value
// // all multiplications repeat only like 2*4 is 8 then why
// // should we check if 8 is dicvisble by 4 or not.
    

//             if(n%i==0){
//                 return false;
//             }
//         }
//         return true;
// }
// int main(){
//     int a,b;
//     cout<<"Enter a: ";
//     cin>>a;
//     cout<<"Enter b: ";
//     cin>>b;
//     for(int i=a;i<=b;i++){
//         if(is_Prime(i)==true){
//             cout<<i<<endl;
//         }
//     }
//    return 0;
// }

// // pass by value
// void change(int a,int b){
//     swap(a,b);
// }
// int main(){
//     int x=5,y=3;
//     change(x,y);//we are passing the copies of x and y
//     cout<<x<<" "<<y;
//     return 0;
// }

// //reference variable
// int main(){
//     int x=10;
//     int &y=x;
//     cout<<x<<" "<<y<<endl;
//     y=43;
//     cout<<x<<" "<<y;
//     return 0;
// }

// //pass by reference;
// void change(int &x,int &y){
//     swap(x,y);
// }
// int main(){
//     int x=10;
//     int c=5;
//     int &y=x;
//     change(x,c);
//     cout<<x<<" "<<c;
//     return 0;
// }

// //pointers
// void fun(int *p){
//     cout<<*p;//derefernce operator
// }
// int main(){
//     int x=10;
//     fun(&x);
//     return 0;
// }