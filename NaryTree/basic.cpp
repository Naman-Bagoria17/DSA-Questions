#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        char val;
        vector<Node *> children;
        Node(char data){
            val = data;
        }
};
//All below traversal are of TC->O(N)
void preorder(Node* root){
    if(root==nullptr)
        return;
    cout << root->val << " ";//first print the root node
    for(Node* child:root->children){
        preorder(child);//Then visit the child nodes
    }
    return;//if root has no child then loop will be skipped and we will return
}
void postorder(Node* root){
    if(root==nullptr)
        return;
    for(Node* child:root->children){
        postorder(child);//First visit the child nodes
    }
    cout << root->val << " ";//Then print the root node
    return;
}
void inorder(Node* root){
    //recursively visit child nodes except last
    //print root node
    //visit last child node
    if(root==nullptr)
        return;
    int child_nodes = root->children.size();
    for (int i = 0; i < child_nodes - 1;i++){
        inorder(root->children[i]);
    }
    cout << root->val<<" ";
    if(child_nodes>0)
        inorder(root->children[child_nodes - 1]);
}
void levelOrder(Node* root){
    if(root==nullptr)
        return;
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        int NodesAtCurrLevel = q.size();
        while(NodesAtCurrLevel--){
            Node *curr = q.front();
            q.pop();
            cout << curr->val<<" ";
            for(Node* child:curr->children){
                q.push(child);
            }
        }
    }
}
int main(){
    Node *root = new Node('A');
    root->children.push_back(new Node('B'));
    root->children.push_back(new Node('C'));
    root->children.push_back(new Node('D'));
    root->children[0]->children.push_back(new Node('E'));
    root->children[0]->children.push_back(new Node('F'));
    root->children[2]->children.push_back(new Node('G'));
    cout << "Preorder: ";
    preorder(root);
    cout << endl;
    cout << "Inorder: ";
    inorder(root);
    cout << endl;
    cout << "Postorder: ";
    postorder(root);
    cout << endl;
    cout << "Level order: ";
    levelOrder(root);
}
