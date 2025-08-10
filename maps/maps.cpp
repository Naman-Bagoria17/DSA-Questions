#include<bits/stdc++.h>
using namespace std;
int main(){
    map<string, int> directory = {
        {"Naman", 34432},
        {"Hitesh", 54534},
    };
    
    //using make_pair is not compulsory you can directly pass {"Jatin",53342}
    directory.insert(make_pair("Jatin", 53342));//O(logn)

    directory["Jayant"]=75353;

    for(auto ele:directory){
        cout << ele.first << setw(20) << ele.second << endl;
    }
    cout << endl;

    //inserting duplicate key
    directory["Naman"] = 43242;  //value gets updated

    directory.insert(make_pair("Jatin", 89787)); //insert function does not update the value 

    for(auto ele:directory){
        cout << ele.first << setw(20) << ele.second << endl;
    }
    cout << endl;

    //Deleting elements
    
    //Iterator
    auto itr = directory.begin();
    advance(itr, 3);
    directory.erase(itr);
    for(auto ele:directory){
        cout << ele.first << setw(20) << ele.second << endl;
    }
    cout << endl;
    directory["Naman"] = 43242;  

    //Through key 
    directory.erase("Jayant");
    for(auto ele:directory){
        cout << ele.first << setw(20) << ele.second << endl;
    }
    cout << endl;
    directory["Jayant"] = 75353;

    //Deleting a range
    auto itr1 = directory.begin();//at Hitesh
    auto itr2 = directory.begin();
    advance(itr2, 2);//At Jayant
    directory.erase(itr1, itr2);//excludes Jayant(itr2)

    for(auto ele:directory){
        cout << ele.first << setw(20) << ele.second << endl;
    }
    cout << endl;
    directory["Jatin"] = 54534;
    directory["Hitesh"] = 53342;
}