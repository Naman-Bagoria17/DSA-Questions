#include<bits/stdc++.h>
using namespace std;
//same as level order par har level pe element queue me daalne ke baad 
//hum print ni krenge but stack me push krenge
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
void ReverseLevelOrder(Node* root){
    if(root==nullptr)
        return;
    queue<Node *> q;
    stack<Node *> s;
    q.push(root);
    while(!q.empty()){
            Node *currNode = q.front();
            q.pop();
            s.push(currNode);
            if(currNode->right){
                q.push(currNode->right);
            }
            if(currNode->left){
                q.push(currNode->left);
            }
    }
    while(!s.empty()){
        cout << s.top()->data << " ";
        s.pop();
    }
}
int main(){
    Node *root = new Node(2);
    root->left= new Node(4);
    root->right = new Node(10);
    root->left->left = new Node(6);
    root->left->right = new Node(5);
    root->right->left = new Node(11);
    ReverseLevelOrder(root);
}