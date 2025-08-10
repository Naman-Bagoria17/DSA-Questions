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
vector<int> topViewNodes(Node* root){
    vector<int> ans;
    if(root==nullptr)
        return ans;
    queue<pair<Node*,int>> q;
    map<int, int> m;//to store pehli value jo milegi har column me
    q.push(make_pair(root,0));
    while(!q.empty()){
        int NodeAtCurrentLevel = q.size();//this will give that particular level pe kitne nodes hai
        while(NodeAtCurrentLevel--){
            pair<Node*,int> p=q.front();
            Node *currNode = p.first;
            int currCol = p.second;
            q.pop();
            if(m.find(currCol)==m.end()){
                m[currCol] = currNode->data;
            }
            if(currNode->left){
                q.push(make_pair(currNode->left,currCol-1));
            }
            if(currNode->right){
                q.push(make_pair(currNode->right,currCol+1));
            }
        }
    } 
    for(auto it:m){
        ans.push_back(it.second);
    }
    return ans;
}
int main(){
    Node *root = new Node(2);
    root->left= new Node(4);
    root->right = new Node(10);
    root->left->left = new Node(6);
    root->left->right = new Node(5);
    root->right->right = new Node(11);
    vector<int> result=topViewNodes(root);
    for(auto ele:result){
        cout << ele << " ";
    }
}