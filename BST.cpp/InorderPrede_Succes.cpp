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
Node* findJustSmaller(Node* root,int value){
    if(root->right==nullptr)
        return root;
    return findJustSmaller(root->right, value);
}
Node* findJustGreater(Node* root,int value){
    if(root->left==nullptr)
        return root;
    return findJustGreater(root->left, value);
}
void InorderPreSuc(Node* root,Node*& pre,Node* &succ,int key){
    if(root==nullptr)
        return;
    if(root->val==key){
        if(root->left) pre = findJustSmaller(root->left, root->val);
        if(root->right) succ = findJustGreater(root->right, root->val);
    }
    else if(root->val>key){
        succ = root;
        InorderPreSuc(root->left, pre, succ, key);
    }
    else{
        pre = root;
        InorderPreSuc(root->right, pre, succ, key);
    }
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
    Node *predecessor = nullptr;
    Node *successor = nullptr;
    int key;
    cout << "Enter the node value: ";
    cin >> key;
    InorderPreSuc(b.root, predecessor, successor, key);
    if(predecessor){
        cout << "Predecessor: " << predecessor->val << endl;
    }
    else{
        cout << "Predecessor not exist!!" << endl;
    }
    if(successor){
        cout << "Successor: " << successor->val << endl;
    }
    else{
        cout << "Successor not exist!!" << endl;
    }
}