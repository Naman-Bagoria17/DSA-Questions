#include<iostream>
using namespace std;
int main(){
    int apples;
    cin>>apples; // if u enter float then integer part will be considered
                 // if u enter character then 0 will be stored in apples
    cout<<"number of apples are"<<endl<<apples;
    return 0;

}