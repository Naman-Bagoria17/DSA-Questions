//return the preorder traversal before and after removing the leaf nodes
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int val;
        Node *left;
        Node* right;
        Node(int data){
            val = data;
            left = right = nullptr;
        }
};
class BST{
    public:
        Node *root;
    BST(){
        root = nullptr;
    }
};
void insertRecursive(Node* &root,int value){
    if(root==nullptr){
        Node *new_node = new Node(value);
        root = new_node;
        return;
    }
    if(root->val>value){
        if(!root->left){
            Node *new_node = new Node(value);
            root->left = new_node;
            return;
        }
        else{
            insertRecursive(root->left,value);
        }
    }
    else{
        if(!root->right){
            Node *new_node = new Node(value);
            root->right = new_node;
            return;
        }
        else{
            insertRecursive(root->right,value);
        }
    }
}
bool isValidBST(Node* root,int pre){
    if(root==nullptr){
        return true;
    }
    //yaha pe humne sidha return statement nahi likha qki fir sirf left most node 
    //ko jake call krke true return krdega aur hum function se bahar aa jayenge
    if(!isValidBST(root->left,pre)){//left subtree
        return false;
    }
    if(root->val<pre)//root node
        return false;
    pre = root->val;

    return isValidBST(root->right, pre);//right subtree
    //yaha pe hum return statement likh skte qki right side vaali 
    //nodes ke baad kuchh check krne ke liye bchega hi ni
}
int main(){
    BST b;
    insertRecursive(b.root, 4);
    insertRecursive(b.root, 2);
    insertRecursive(b.root, 6);
    insertRecursive(b.root, 5);
    insertRecursive(b.root, 7);
    insertRecursive(b.root, 1);
    insertRecursive(b.root, 3);
    cout << isValidBST(b.root, INT_MIN);
}