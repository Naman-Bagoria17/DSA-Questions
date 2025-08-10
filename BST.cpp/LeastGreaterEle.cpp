#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int data){
            val = data;
            left = right = nullptr;
        }
};
TreeNode* insertEle(TreeNode* root,int ele,int &successor){
    if(!root)
        return new TreeNode(ele);
    if(root->val>ele){
        successor = root->val;
        root->left = insertEle(root->left, ele, successor);
    }
    else{
        root->right = insertEle(root->right, ele, successor);     
    }
    return root;
}
void replaceWithLeastGreaterEle(vector<int> &v){
    TreeNode *root = nullptr;
    for (int i = v.size() - 1; i >= 0;i--){
        int successor = -1;
        root = insertEle(root, v[i], successor);
        v[i] = successor;
    }
}
int main(){
    int n;
    cout << "Enter size: ";
    cin >> n;
    vector<int> v;
    while(n--){
        int ele;
        cin >> ele;
        v.push_back(ele);
    }
    replaceWithLeastGreaterEle(v);
    for(int ele: v){
        cout << ele << " ";
    }
    return 0;
}