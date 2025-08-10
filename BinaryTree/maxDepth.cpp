//maxDepth-number of nodes along the longest path from root node to farthest leaf node

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
//recursively we can check maximum depth out of left and right sub-tree
int maxDepth(Node* root){
    if(root==nullptr)
        return 0;
    return max(maxDepth(root->left), maxDepth(root->right))+1;//1 added for root node
}
int main(){
    Node *root = new Node(2);
    root->left= new Node(4);
    root->right = new Node(10);
    root->left->left = new Node(6);
    root->left->right = new Node(5);
    root->right->left = new Node(11);
    int result = maxDepth(root);
    cout << "Result: " << result << endl;
}