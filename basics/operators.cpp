#include<iostream>
using namespace std;
int main(){
    int num1=5; //0101
    int num2=6; //0110

    // cout<<(num1==num2)<<endl; //gives 0
    // cout<<int(num1==num2)<<endl; //gives 0
    // cout<<bool(num1==num2)<<endl; // gives 0
    // cout<<char(num1==num2)<<endl;//no output
    // cout<<float(num1==num2)<<endl;//gives 0 

    // cout<<(num1<=num2)<<endl; //gives 1
    // cout<<int(num1<=num2)<<endl; //gives 1
    // cout<<bool(num1<=num2)<<endl; // gives 1
    // cout<<char(num1<=num2)<<endl;//smiley emoji //no output on command prompt
    // cout<<float(num1<=num2)<<endl;//gives 1

    
    // bool exp1= true;
    // bool exp2= false;
    
    // cout<<bool(exp1 && exp2)<<endl; // will give 0 not false.why?
    // cout<<(exp1 || exp2)<<endl; 
    // cout<<(!exp1)<<endl; 
   

    // cout<<(num1<<1)<<endl; //10
    // cout<<(num2>>2)<<endl; //6 divided by 4
    // cout<<(~num2)<<endl; //sign change and decrease by 1
    // cout<<(num1&num2)<<endl; //4
    // cout<<(num1|num2)<<endl; //7
    // cout<<(num1^num2)<<endl; //3
    
    // string name_1="naman"; //24.on a 64 bit system it is usually around 24 bytes
    // wchar_t name_2= L'R'; //2
    // std::wstring name_3= L"raman"; //24
    // char name_4='n';  //1
    // cout<<sizeof(name_1)<<endl;
    // cout<<sizeof(name_2)<<endl;
    // cout<<sizeof(name_3)<<endl;
    // cout<<sizeof(name_4)<<endl;
    
    // int a=10;
    // int b= a++; //b=10 a=11
    // cout<<b<<endl;//10
    // b=++a;//b=12 a=12
    // cout<<b<<endl;//12
    
    // cout<<(30>20>10);//0 because associativity is from left to right..30>20 gives 1 and 1>10 gives 0

    // int p=1,q=1;
    // int r= p || --q; //short circuiting-- first expression hi true hai to second vala evaluate hi ni hoga.
    // int s= p-- && --q; // 1(post) && 0(pre)
    // cout<<p<<q<<r<<s<<endl; //0010


    return 0;

}