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
//for Every Node we are checking if it is greater than x
//TC-O(N)
//SC-O(m),m->max number of nodes at particular level
int justGreater(Node* root,int x){
    if(root==nullptr)
        return -1;
    int minGreater = INT_MAX;
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        int NodesAtCurrLevel = q.size();
        while(NodesAtCurrLevel--){
            Node *curr = q.front();
            q.pop();
            if(curr->val>x){
                minGreater = min(minGreater, curr->val);
            }
            for(Node* child:curr->children){
                q.push(child);
            }
        }
    }
    if(minGreater==INT_MAX)
        return -1;
    else
        return minGreater;
}

//for Every Node we are checking if it is greater than x
//TC-O(N)
//SC-O(h),h->recursion stack
void JustGreaterRecursive(Node* root,int x,Node* &ans){
    if(root==nullptr)
        return;
    if(root->val>x && (ans==nullptr/*bcz nullptr ka data ni hota*/ || root->val<ans->val)){
        ans = root;
    }
    for(Node* child:root->children){
        JustGreaterRecursive(child, x, ans);
    }
    return;
}
int main(){
    Node *root = new Node(20);
    root->children.push_back(new Node(8));
    root->children.push_back(new Node(22));
    root->children[0]->children.push_back(new Node(4));
    root->children[0]->children.push_back(new Node(12));
    root->children[0]->children[1]->children.push_back(new Node(10));
    root->children[0]->children[1]->children.push_back(new Node(14));
    int x;
    cout << "Enter x: ";
    cin >> x;
    cout << "Just Greater Element than x is: " << justGreater(root,x);
    Node *ans = nullptr;
    JustGreaterRecursive(root, x, ans);
    cout << endl
         << "Recursively: " << endl;
    if(ans==nullptr)
        cout << "NULL";
    else
        cout << ans->val;
    return 0;
}
