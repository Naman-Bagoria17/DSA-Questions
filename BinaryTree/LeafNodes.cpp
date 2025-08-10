#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int val){
            data = val;
            left = right = nullptr;
        }
};
int totalLeafNodes(Node* root){
    if(!root)
        return 0;
    if(!root->left && !root->right)
        return 1;
    return totalLeafNodes(root->left)+totalLeafNodes(root->right);
}
int main(){
    Node *root = new Node(2);
    root->left= new Node(4);
    root->right = new Node(10);
    root->left->left = new Node(6);
    root->left->right = new Node(5);
    root->right->left = new Node(11);
    int result = totalLeafNodes(root);
    cout << "Result: " << result << endl;
}