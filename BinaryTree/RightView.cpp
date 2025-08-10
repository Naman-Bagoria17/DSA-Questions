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
void rightmostNodes(Node* root){
    if(root==nullptr)
        return;
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        int NodeAtCurrentLevel = q.size();
        while(NodeAtCurrentLevel){
            Node *currNode = q.front();
            q.pop();
            if(NodeAtCurrentLevel==1)
                cout << currNode->data << " ";
            if(currNode->left){
                q.push(currNode->left);
            }
            if(currNode->right){
                q.push(currNode->right);
            }
            NodeAtCurrentLevel--;
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
    rightmostNodes(root);
}