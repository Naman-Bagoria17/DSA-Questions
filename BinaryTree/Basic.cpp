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
void preOrderTraversal(Node* root){
    //basecase
    if(root==nullptr)
        return;
    cout << root->data << " ";
    //recursion
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void InOrderTraversal(Node* root){
    if(root==nullptr)
        return;
    InOrderTraversal(root->left);
    cout << root->data << " ";
    InOrderTraversal(root->right);
}
void PostOrder(Node* root){
    if(root==nullptr)
        return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}
void LevelOrder(Node* root){
    if(root==nullptr)
        return;
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        int NodeAtCurrentLevel = q.size();//this will give that particular level pe kitne nodes hai
        while(NodeAtCurrentLevel--){
            Node *currNode = q.front();
            q.pop();
            cout << currNode->data << " ";
            if(currNode->left){
                q.push(currNode->left);
            }
            if(currNode->right){
                q.push(currNode->right);
            }
        }
        cout << endl;
    }
}
int main(){
    Node *root = new Node(2);
    root->left= new Node(4);
    root->right = new Node(10);
    root->left->left = new Node(6);
    root->left->right = new Node(5);
    root->right->left = new Node(11);
    preOrderTraversal(root);
    cout << endl;
    InOrderTraversal(root);
    cout << endl;
    PostOrder(root);
    cout << endl;
    LevelOrder(root);
}