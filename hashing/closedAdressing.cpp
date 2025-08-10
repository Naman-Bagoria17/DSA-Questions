// Implement a hash table using closed addressing
#include<bits/stdc++.h>
using namespace std;
//now first we have to store elements at indices
//therefore we can use vector for that(#include<vector>)
//As we have to do separate chaining therefore
//type of vector can be linked list(#include<list>)

//Every function below is O(1) in average case
class Hashing{
    vector<list<int>> hashtable;
    int buckets;//size of hashtable
    public:
    Hashing(int size){
        buckets = size;
        hashtable.resize(size);
    }

    //HashFunction
    int hashValue(int key){
        return key % buckets;//division method
    }

    //inserting elements in hashtable
    void add_key(int key){
        int idx = hashValue(key);
        //insert value at end of the linked list present at idx
        hashtable[idx].push_back(key);//here push_back is function of linked list
        //remember hashtable[idx] is returning a linked list
    }

    //searching
    //returns-an iterator to the key in the linked list present at idx if key is present
    //otherwise end iterator
    list<int>:: iterator search_key(int key){
        int idx = hashValue(key);
        return find(hashtable[idx].begin(), hashtable[idx].end(), key);
        //find(kaha se,kaha tk, kisko find krna hai)
    }

    void delete_key(int key){
        int idx = hashValue(key);
        //check if the value is present in the hashtable or not
        if(search_key(key)!=hashtable[idx].end()){
            //I have to pass iterator the element in the erase function
            //that i can get using search function
            hashtable[idx].erase(search_key(key));
            cout << "Key is deleted!!" << endl;
        }
        else{
            cout << "Key is not present in the hashtable!!" << endl;
        }
    }
};
int main(){
    Hashing h(10);
    h.add_key(5);
    h.add_key(9);
    h.add_key(3);
    h.delete_key(3);
    h.delete_key(3);
}