#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int val;
        Node *left;
        Node *right;
        Node(int data){
            val = data;
            left = right = nullptr;
        }
};
void InOrderTraversal(Node* root){//InOrderTraversal of BST is always sorted
    if(root==nullptr)
        return;
    InOrderTraversal(root->left);
    cout << root->val << " ";
    InOrderTraversal(root->right);
}
class BST{
    public:
        Node *root;
    BST(){
        root = nullptr;
    }
    void insert(int value){
        Node *new_node = new Node(value);
        if(root==nullptr){
            root = new_node;
            return;
        }
        Node *curr = root;
        while(true){
            if(curr->val>value){
                if(!curr->left){
                    curr->left = new_node;
                    return;
                }
                else{
                    curr = curr->left;
                }
            }
            else{
                if(!curr->right){
                    curr->right = new_node;
                    return;
                }
                else{
                    curr = curr->right;
                }
            }
        }
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
bool search(Node* root,int value){
    if(root==nullptr)
        return false;
    if(root->val==value)
        return true;      
    if(root->val>value){
        return search(root->left, value);
    }
    if(root->val<value){
        return search(root->right, value);
    }
}
int findJustSmaller(Node* root,int value){
    if(root->right==nullptr)
        return root->val;
    return findJustSmaller(root->right, value);
}
Node* deleteNode(Node* &root,int value){
    if(root==nullptr)
        return nullptr;
    if(root->val>value) root->left= deleteNode(root->left, value);
    else if(root->val<value) root->right= deleteNode(root->right, value);
    //we are assigning values above beacuse recursively jb node delete hogi to uske child ko
    //uper vaali node(grandparent) ke left ya right me lagana pdega acc. to the case
    else{
        if(root->left==nullptr && root->right==nullptr){
            free(root);
            return nullptr;//return nullptr
        }
        else if(root->left==nullptr){
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==nullptr){
            Node *temp = root->left;
            free(root);
            return temp;
        }
        else{
            int justSmaller = findJustSmaller(root->left, value);
            root->val = justSmaller;
            root->left = deleteNode(root->left, justSmaller); // make sure to assign the value to root->left
        }
    }
}
int main(){
    BST bst1;
    insertRecursive(bst1.root,5);
    insertRecursive(bst1.root,3);
    bst1.insert(9);
    insertRecursive(bst1.root,10);
    insertRecursive(bst1.root,1);
    InOrderTraversal(bst1.root);
    cout << endl;
    cout<<search(bst1.root, 1)<<endl;
    cout<<search(bst1.root, 10)<<endl;
    cout<<search(bst1.root, 15)<<endl;
    deleteNode(bst1.root, 9);
    InOrderTraversal(bst1.root);
    cout << endl;
    deleteNode(bst1.root, 5);
    InOrderTraversal(bst1.root);
    return 0;
}

//height of Binary tree=log(base2)(n+1)=O(logn)
//if a node is at index i then its left child is at index 2*i
//right child at index 2*i+1
//AVL tree=balanced BST