// The problem is about incrementing a given non-negative integer by one. 
// However, the integer isn't represented in the traditional numerical form; 
// it's represented as a linked list, with each node containing a single digit. 
// The head of the linked list contains the most significant digit (MSD), 
// while the tail contains the least significant digit (LSD). 
// For example, the integer 123 would be represented as a linked list 1 -> 2 -> 3.

// The goal is to add one to this integer and return the 
// resulting linked list following the same MSD to LSD format. 
// The problem must be solved in such a way that the linked list
// structure is mantained, without converting the entire list to an
// integer or a series of strings.

#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node *next;
    Node(int data){
        val = data;
        next = nullptr;
    }
};
class LinkedList{
    public:
    Node* head;
    LinkedList(){
        head=nullptr;
    }
    void insert_at_end(int val){
        Node* new_node= new Node(val);
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
            cout<<temp->val<<"->";
            temp=temp->next;
        }cout<<"NULL"<<endl;
    }
    Node* plus_one(){
        if(head==nullptr){
            return head;
        }
        Node *temp_head = new Node(-1);
        temp_head->next = head;
        Node *current = head;
        Node *target=temp_head;
        while(current){
            if((current->val)<9){
                target = current;
            }
            current = current->next;
        }
        target->val += 1;
        target = target->next;
        while(target){
            target->val = 0;
            target = target->next;
        }
        if(temp_head->val==-1){
            return head;
        }
        else{
            temp_head->val += 1;
            return temp_head;
        }
    }
};
int main(){
    LinkedList ll;
    ll.insert_at_end(1);
    ll.insert_at_end(9);
    ll.insert_at_end(2);
    ll.display();
    ll.head=ll.plus_one();
    ll.display();
}