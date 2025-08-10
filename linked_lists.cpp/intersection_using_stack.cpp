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
            cout<<temp->value<<"->";
            temp=temp->next;
        }cout<<"NULL"<<endl;
    }
};
int length(Node* head){
    int size=0;
    Node* temp=head;
    while(temp!=nullptr){
        size++;
        temp=temp->next;
    }
    return size; 
}
// int my_find_interseaction(Node* head1,Node* head2){
//     stack<Node*> st;
//     Node *temp1 = head1;
//     Node *temp2 = head2;
//     int m = length(head1);
//     int n = length(head2);
//     if(m>n){  
//         int i = 1;
//         while(i<=m-n){
//             temp1 = temp1->next;
//             i++;
//         }
//     }
//     if(n>m){
//         int i = 1;
//         while(i<=n-m){
//             temp2 = temp2->next;
//             i++;
//         }      
//     }
//     st.push(temp1);
//     while(st.top()!=temp2){
//         st.pop();
//         temp1 = temp1->next;
//         temp2 = temp2->next;
//         st.push(temp1);
//     }
//     return st.top()->value;
// }

int Another_method(Node* head1,Node * head2 ){
    stack<Node *> s1, s2;
    Node *temp1 = head1;
    while(temp1){
        s1.push(temp1);
        temp1 = temp1->next;
    }
    Node *temp2 = head2;
    while(temp2){
        s2.push(temp2);
        temp2 = temp2->next;
    }
    int intersection = INT_MIN;
    while(!s1.empty() && !s2.empty() && s1.top()==s2.top()){
            intersection = s1.top()->value;
            s1.pop();
            s2.pop();
    }
    return intersection;
}
int main(){
    LinkedList l1,l2;
    l1.insert_at_end(1);
    l1.insert_at_end(2);
    l1.insert_at_end(3);
    l1.insert_at_end(4);
    l1.insert_at_end(5);
    l1.insert_at_end(6);
    l1.insert_at_end(7);
    l1.insert_at_end(8);
    l1.insert_at_end(9);
    l2.insert_at_end(19);
    l2.insert_at_end(20);
    l2.insert_at_end(21);
    l2.insert_at_end(23);
    l2.head->next->next->next->next = l1.head->next->next->next->next->next;
    // int val = find_interseaction(l1.head, l2.head);
    int val = Another_method(l1.head, l2.head);
    cout << val;
}