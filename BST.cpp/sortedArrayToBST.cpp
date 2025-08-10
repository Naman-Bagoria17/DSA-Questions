//create a balanced BST from given sorted array
#include<bits/stdc++.h>
using namespace std;
//if we find the root node then other task is easy
//and middle element of sorted array can be made root node so that tree is balanced
class Node{
    public:
        int data;
        Node *left;
        Node* right;
        Node(int data){
            this->data = data;
            left = right = nullptr;
        }
};
//TC-O(n)
//Sc-O(h) where h is height of balanced BST ,thus h=logn
//because h is the maximum number of calls in recursion stack
Node* ArrayToBST(int *arr,int st,int end){
    if(st>end){
        return nullptr;
    }
    int mid = ((st + end) / 2);
    Node *root = new Node(arr[mid]);
    root->left = ArrayToBST(arr, st, mid - 1);
    root->right = ArrayToBST(arr, mid + 1, end);
    return root;
}
void PreOrderTraversal(Node* root){
    if(root==nullptr)
        return;
    cout << root->data << " ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}
int main(){
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements in sorted order: ";
    int i = 0;
    while(i<n){
        cin >> arr[i];
        i++;
    }
    Node *root = ArrayToBST(arr, 0, n - 1);
    PreOrderTraversal(root);
}