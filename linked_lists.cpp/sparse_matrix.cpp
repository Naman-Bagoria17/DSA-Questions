#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int row;
    int column;
    int val;
    Node* next;
    Node(int r,int c,int data){
        row = r;
        column = c;
        val = data;

        next=nullptr;
    }
};
class LinkedList{
    public:
    Node* head; 
    LinkedList(){
        head=nullptr;
    }
    void insert_at_end(int r,int c,int data){
        Node* new_node= new Node(r,c,data);
        if(head==nullptr){
            head=new_node;
        }
        else{
            Node*temp=head;
            while(temp->next){
                temp=temp->next;
            }temp->next=new_node;
        }
    }
    void display(){
        Node* temp=head;
        while(temp){
            cout<<temp->row<<" "<<temp->column<<" "<<temp->val<<"->";
            temp=temp->next;
        }cout<<"NULL"<<endl;
    }
    LinkedList add(Node* &other){
        Node *a = this->head;
        Node *b = other;
        LinkedList result;
        while(a && b){
            if(a->row==b->row){
                if(a->column==b->column){
                    result.insert_at_end(b->row,b->column,a->val+b->val);
                    a = a->next;
                    b = b->next;
                }
                else if(a->column<b->column){
                    result.insert_at_end(a->row,a->column,a->val);
                    a = a->next;           
                }
                else{
                    result.insert_at_end(b->row,b->column,b->val);
                    b = b->next; 
                }
            }
            else{
                if(a->row<b->row){
                    result.insert_at_end(a->row,a->column,a->val);
                    a = a->next;           
                }
                else{
                    result.insert_at_end(b->row,b->column,b->val);
                    b = b->next; 
                }
            }
        }
        while(a){
            result.insert_at_end(a->row,a->column,a->val);
            a = a->next;                 
        }
        while(b){
            result.insert_at_end(b->row,b->column,b->val);
            b = b->next; 
        }
        return result;
    }
};
int main(){
    int arr1[][3] = {0, 4, 0, 3, 0, 0, 0, 0, 5};
    int arr2[][3] = {0, 2, 0, 1, 0, 0, 0, 0, 7};
    for (int i = 0; i < 3;i++){
        for (int j = 0; j < 3;j++){
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < 3;i++){
        for (int j = 0; j < 3;j++){
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }
    LinkedList l1;
    for (int i = 0; i < 3;i++){
        for (int j = 0; j < 3;j++){
            if(arr2[i][j]!=0){
                l1.insert_at_end(i, j, arr1[i][j]);
            }
        }
    }
    l1.display();
    LinkedList l2;
    for (int i = 0; i < 3;i++){
        for (int j = 0; j < 3;j++){
            if(arr2[i][j]!=0){
                l2.insert_at_end(i, j, arr2[i][j]);
            }
        }
    }
    l2.display();
    LinkedList sp;
    sp = l1.add(l2.head);
    sp.display();
}