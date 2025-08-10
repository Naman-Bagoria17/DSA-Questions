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
void PreOrderTraversal(Node* root){
    if(root==nullptr)
        return;
    cout << root->val << " ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}
//TC-O(n)
//Sc-O(h) where h is height of balanced BST ,thus h=logn
//and it is maximum depth of recursion stack
Node* removeLeafNodes(Node* &root){//return type is node* because
                                  // we can't directly remove node
                                  //we have to return nullptr to its parent
    if(root==nullptr)
        return root;
    if(root->left==nullptr && root->right==nullptr){
        return nullptr;
    }
    root->left= removeLeafNodes(root->left);
    root->right= removeLeafNodes(root->right);

    return root;//if node is not leaf node then it will be returned to its parent
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
    PreOrderTraversal(b.root);
    cout << endl;
    b.root=removeLeafNodes(b.root);
    PreOrderTraversal(b.root);
    cout << endl;
}