#include<bits/stdc++.h>
using namespace std;
int main(){
    // list<int> l1={1,2,3,4,43,46};
    // auto itr=l1.begin();//iterator pointing to the first element 
    // cout<<*itr<<endl;
    // auto itr2=l1.end();//iterator pointing to memory location after 5
    // cout<<*itr2<<endl;
    // auto itr3=l1.rbegin();//itertor pointing to first element in reverse iteration
    // cout<<*itr3<<endl;
    // auto itr4=l1.rend();//iterator pointing to the position after the last element in reverse iteration
    // cout<<*itr4<<endl;
    // auto itr5=l1.begin();
    // ++itr5;//now points to 2
    // cout<<*itr5<<endl;
    // advance(itr5,2);//advances the iterator by 2 places(now points to 4)
    // cout<<*itr5<<endl;

    // //traversal(using range based loop)
    // list<int> l={1,2,3,4,5,6};
    // for(auto num:l){
    //     cout<<num<<"\t";
    // }

    // //using iterators
    // list<int> l2={1,2,3,4,5,6};
    // for(auto itr=l2.begin();itr!=l2.end();itr++){
    //     cout<<*itr<<"\t";
    // }
    
    // //reverse traversal
    // list<int> l3={1,2,3,4,5};
    // for(auto itr=l3.rbegin();itr!=l3.rend();itr++){
    //     cout<<*itr<<"\t";
    // }

    // //inserting elements
    // list<int> l={1,2,3,4,5,6};
    // auto itr=l.begin();
    // l.insert(itr,89);
    // for(auto num:l){
    //     cout<<num<<"\t";
    // }cout<<endl;
    // // 89 1 2 3 4 5 6
    // advance(itr,3);//now itr is pointing to 4(because itr was still pointing to 1)
    // l.insert(itr,76);
    // for(auto num:l){
    //     cout<<num<<"\t";
    // }cout<<endl;
    // // 89 1 2 3 76 4 5 6
    // l.insert(itr,3,65);
    // //89 1 2 3 76 65 65 65 4 5 6
    // for(auto num:l){
    //     cout<<num<<"\t";
    // }cout<<endl;
    // //itr is pointing to 4
    // auto l1=l.begin();//pointing to 89
    // auto r=l.begin();
    // advance(r,3);
    // //r pointing to 3
    // l.insert(itr,l1,r);//insert 89 1 2 before 4
    // for(auto num:l){
    //     cout<<num<<"\t";
    // }cout<<endl;

    // //deletion 
    // //remove 89
    // auto del_itr=l.begin();
    // l.erase(del_itr);
    // for(auto num:l){
    //     cout<<num<<"\t";
    // }cout<<endl;
    // del_itr=l.begin();
    // //remove 5
    // advance(del_itr,11);
    // l.erase(del_itr);
    // for(auto num:l){
    //     cout<<num<<"\t";
    // }cout<<endl;
    // //remove two 65 after 76
    // auto s=l.begin();
    // advance(s,4);
    // auto e=l.begin();
    // advance(e,6);
    // l.erase(s,e);
    // for(auto num:l){
    //     cout<<num<<"\t";
    // }cout<<endl;  
}