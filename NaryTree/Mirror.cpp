#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int val;
        vector<Node *> children;
        Node(int data){
            val = data;
        }
};
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
        cout << endl;
    }
}
//TC-O(N),we are going at every node and reversing its children vector
//SC-O(h+m),h->recursion stack,m->max number of nodes at particular level
void CreateMirror(Node *&root)
{
    if(root==nullptr)
        return;
    if(root->children.size<2)
        return;//no need to reverse for 0 or 1 children
    reverse(root->children.begin(), root->children.end());
    for(Node* child:root->children){
        CreateMirror(child);
    }
}
int main(){
    Node *root = new Node(20);
    root->children.push_back(new Node(8));
    root->children.push_back(new Node(22));
    root->children[0]->children.push_back(new Node(4));
    root->children[0]->children.push_back(new Node(12));
    root->children[0]->children[1]->children.push_back(new Node(10));
    root->children[0]->children[1]->children.push_back(new Node(14));
    cout << "Level Order: " << endl;
    levelOrder(root);
    CreateMirror(root);
    cout << endl
         << "After Mirroring: " << endl;
    levelOrder(root);
    return 0;
}
