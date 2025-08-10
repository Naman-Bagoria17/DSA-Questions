#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int value;
    Node* next;
    Node(int data){
        value=data;
        next=nullptr;
    }
};
class CircularLL{
    public:
    Node* head;
    CircularLL(){
        head=nullptr;
    }
    void insertAtStart(int val){//O(n)
        Node* new_node=new Node(val);
        if(head==nullptr){
            head=new_node;
            new_node->next=head;//to make it circular linked list
            return;
        }
        Node* tail=head;
        while(tail->next!=head){
            tail=tail->next;
        }
        tail->next=new_node;
        new_node->next=head;
        head=new_node;//we are changing the head here
    }
    void insertAtEnd(int val){//O(n)
        Node* new_node=new Node(val);
        if(head==nullptr){
            head=new_node;
            new_node->next=head;
            return;
        }
        Node* tail=head;
        while(tail->next!=head){
            tail=tail->next;
        }
        tail->next=new_node;
        new_node->next=head;
        //not changing the head here
    }
    void insert_at_arbitrary(int val,int k){//considering position start from 0
        //it is same as singly linked list
        if(k==0){
            insertAtStart(val);
            return;
        }
        Node* new_node=new Node(val);
        Node* temp=head;
        int i=1;
        while(i<k)//if k==3 then one jump from 0 to 1 and other from 1 to 2(2 jumps total)
        {
            temp=temp->next;
            i++;
        }
        Node* next_node=temp->next;
        temp->next=new_node;
        new_node->next=next_node;
    }
    void update_val(Node* &head,int val,int k){//considering position start from 0
        //it is same as singly linked list
        Node* temp=head;
        if(k==0){
            temp->value=val;
        }
        int i=1;
        while(i<=k)
        {
            temp=temp->next;
            i++;
        }
        temp->value=val;
    }
    void display(){
        Node* temp=head;
        do{
            cout<<temp->value<<"->";
            temp=temp->next;
        }while (temp!=head);
        //we didn't use while loop because temp is initially pointing to head and loop will never run!!
        cout<<endl; 
    }
    void check_circular(){
        Node* temp=head;
        do{
            if(temp->next==nullptr){
                cout<<"Not a circular linked list!!";
                return;
            }
            temp=temp->next;
        }while(temp->next!=head);
        cout<<"It is a circular linked list";
    }
    Node* delete_head(){//O(n)
        if(head==nullptr){
            cout<<"NULL";
            return nullptr;
        }
        if(head->next==head){
            free(head);
            return nullptr;
        }
        Node* temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        Node* first=head;
        temp->next=head->next;
        Node* new_head=temp->next;
        free(first);
        return new_head;
    }
    Node* delete_tail(){//O(n)
        if(head==nullptr){
            cout<<"NULL";
            return nullptr;
        }
        if(head->next==head){
            free(head);
            return nullptr;
        }
        Node* tail=head;
        while(tail->next->next!=head){
            tail=tail->next;
        }
        Node* temp=tail->next;
        tail->next=head;
        free(temp);
        return head;
    }
    Node* deleteAtArbitrary(int k){
        if(head==nullptr){
            return nullptr;
        }
        if(k==0){
            Node* new_head= delete_head();  
            return new_head;
        }
        Node* temp=head;
        int i=1;
        while(i<k){
            temp=temp->next;
            i++;
        }
        Node* del_node=temp->next;
        temp->next=del_node->next;
        free(del_node);
        return head;
    }

};
int main(){
    CircularLL cll;
    cll.insertAtStart(1);
    cll.insertAtStart(2);
    cll.insertAtStart(3);
    cll.insertAtStart(4);
    cll.insertAtStart(5);
    cll.display();
    cll.check_circular();

    // CircularLL cll;
    // cll.insertAtEnd(1);
    // cll.insertAtEnd(2);
    // cll.insertAtEnd(3);
    // cll.insertAtEnd(4);
    // cll.insertAtEnd(5);
    // cll.display();
    // cll.check_circular();

    // CircularLL cll;
    // cll.insertAtEnd(1);
    // cll.insertAtEnd(2);
    // cll.insertAtEnd(3);
    // cll.insertAtEnd(4);
    // cll.insertAtEnd(5);
    // cll.display();
    // cout<<"enter value: ";
    // int val;
    // cin>>val;
    // int pos;
    // cout<<"enter position: ";
    // cin>>pos;
    // cll.insert_at_arbitrary(val,pos);
    // cll.display();
    // cll.check_circular();

    // CircularLL cll;
    // cll.insertAtEnd(1);
    // cll.insertAtEnd(2);
    // cll.insertAtEnd(3);
    // cll.insertAtEnd(4);
    // cll.insertAtEnd(5);
    // cll.display();
    // cout<<"enter value: ";
    // int val;
    // cin>>val;
    // int pos;
    // cout<<"enter position: ";
    // cin>>pos;
    // cll.update_val(cll.head,val,pos);
    // cll.display();

    // CircularLL cll;
    // cll.insertAtEnd(1);
    // cll.insertAtEnd(2);
    // cll.insertAtEnd(3);
    // cll.insertAtEnd(4);
    // cll.insertAtEnd(5);
    // cll.display();
    // cll.head=cll.delete_head();
    // cll.display();
    // cll.check_circular();

    // CircularLL cll;
    // cll.insertAtEnd(1);
    // cll.insertAtEnd(2);
    // cll.insertAtEnd(3);
    // cll.insertAtEnd(4);
    // cll.insertAtEnd(5);
    // cll.display();
    // cll.head=cll.delete_tail();
    // cll.display();
    // cll.check_circular();

    // CircularLL cll;
    // cll.insertAtEnd(1);
    // cll.insertAtEnd(2);
    // cll.insertAtEnd(3);
    // cll.insertAtEnd(4);
    // cll.insertAtEnd(5);
    // cll.display();
    // cll.head=cll.deleteAtArbitrary(0);
    // cll.display();
    // cll.check_circular();

}