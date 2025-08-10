#include <iostream>
using namespace std;
int main(){
    int a,b,c;
    cout<<"enter a: ";
    cin>>a;
    cout<<"enter b: ";
    cin>>b;
    c=a;
    a=b;
    b=c;
    cout<<"the new value of a is "<< a <<endl;
    cout<<"the new value of b is "<< b;
    return 0;
}