#include<bits/stdc++.h>
using namespace std;
//two pointers are used when you want linear time complexity
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
void print(Node* head){
    Node* temp=head; //initially pointing to head
    while(temp!=nullptr){
        cout<<temp->value<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
bool check_equal(Node* head1, Node* head2){//pass by value
    Node* temp1=head1;
    Node* temp2=head2;
    while(temp1!=nullptr && temp2!=nullptr){
        if(temp1->value!=temp2->value){
            return false;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return (temp1==nullptr && temp2==nullptr);//will return true if both linked lists of same length
}
int length(Node* head){
    int size=0;
    Node* temp=head;
    while(temp!=nullptr){
        size++;
        temp=temp->next;
    }
    return size; 
}
Node* intersection(Node* head1, Node* head2){
    Node* temp1=head1;
    Node* temp2=head2;
    int n=length(head1);//l3
    int m=length(head2);//l4
    int p;
    if(n>m){
    p=n-m;
    for(int i=1;i<=p;i++){
        temp1=temp1->next;
    }
    }
    else{
    p=m-n;
    for(int i=1;i<=p;i++){
        temp2=temp2->next;
    }
    }
    while(temp1!=nullptr || temp2!=nullptr){
        if(temp1==temp2){
            return temp1;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return nullptr;
}
void remove_from_end(Node* &head,int k){//want to change the linked list
    Node* ptr1=head;
    Node* ptr2=head;
    int i=0;
    while(i<k){//moving ptr2 k steps ahead of ptr1
        ptr2=ptr2->next;
        i++;
    }
    if(ptr2==nullptr){//when k is equal to length of the list
        Node*temp=head;
        head=temp->next;
        temp->next = nullptr;
        free(temp);
        return;
    }
    while(ptr2->next!=nullptr){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    //now ptr1 is  before the node to be removed
    Node* temp=ptr1->next;
    ptr1->next=temp->next;
    temp->next = nullptr;
    free(temp);
}
Node* merge_sorted(Node* &head1, Node* &head2){
    Node* temp_head= new Node(-1);
    Node*ptr1=head1;
    Node*ptr2=head2;
    Node* ptr3=temp_head;
    while (ptr1!=nullptr && ptr2!=nullptr){
        if(ptr1->value<ptr2->value){
            ptr3->next=ptr1;
            ptr1=ptr1->next;
        }
        else{
            ptr3->next=ptr2;
            ptr2=ptr2->next;
        }
        ptr3=ptr3->next;
    }
    if(ptr1==nullptr){//to ptr2 vaali linked list ko jor denge
        ptr3->next=ptr2;
    }
    if(ptr2==nullptr){//to ptr1 vaaali linked list ko jor denge
        ptr3->next=ptr1;
    }
    return temp_head->next;
}
Node* merge_sort_k_LL(vector<Node*> &lists){
    if(lists.size()==0){
        return NULL;
    }
    
    while (lists.size()>1)
    {
        Node* merged_head=merge_sorted(lists[0],lists[1]);
        lists.push_back(merged_head);
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
        // vector- head1 head 2 head 3 head 4
        //head1 and head 2 merge
        //vector-head 1 head2 head3 head4 merged_head1
        //vector-head3 head4 merged_head1
        //head3 and head4 merge
        //vector-merged_head1 merged_head2
        //vector-merge_head1 merge_head2 merged_head_final
        //vector- merge_head_final(this will not go in the while loop)

    return lists[0];    
}
void find_middle_ele(Node* head){
    Node* ptr1=head;
    Node* ptr2=head;
    if(ptr2->next==nullptr){//single element
        cout<<ptr1->value;
    }
    while(ptr2->next){
        ptr1=ptr1->next;
        ptr2=ptr2->next->next;
        if(ptr2==nullptr){//even number elements
            cout<<ptr1->value;
            return;
        }
    }
    cout<<ptr1->value;
}
bool check_cycle(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=nullptr && fast->next!=nullptr){//for both even and odd if there is no cycle
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}
void remove_cycle(Node* head){
    Node* slow=head;
    Node* fast=head;
    do{
        slow=slow->next;
        fast=fast->next->next;
    }while(slow!=fast);
    fast=head;
    while(fast->next!=slow->next){
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=nullptr;
}
bool check_palindrome(Node* head){
    if(head==nullptr)
    return NULL;
    if(head->next==nullptr){
        return true;
    }
    Node* slow=head;
    Node* fast=head;
    //finding middle element and breaking connection after that
    do{
        slow=slow->next;
        fast=fast->next->next;
    }while(fast && fast->next);
    //reversing second half
    Node* previous=slow;
    Node* temp=previous->next;
    previous->next=nullptr;
    while(temp){
        Node* next_node=temp->next;
        temp->next=previous;
        previous=temp;
        temp=next_node;
    }
    //checking palindrome
    Node* head1=head;
    Node* head2=previous;
    while(head2->next){//if there are even elements then head2 will be close to null
    //if odd elements then both heads will be at equal distance to null
        if(head1->value!=head2->value){
            return false;
        }
        else{
            head1=head1->next;
            head2=head2->next;
        }
    }
    return true;
}
Node* rotate_k_steps(Node* &head,int k){
    Node* tail=head;
    int length=0;
    while(tail->next!=nullptr){
        tail=tail->next;
        length++;
    }
    length++;//to count last node
    k=k%length;
    if(k==0){
        return head;
    }
    tail->next=head;
    Node* temp=head;
    for(int i=1;i<length-k;i++){
        temp=temp->next;
    }
    //temp is now at n-k node
    Node* new_head=temp->next;
    temp->next=nullptr;
    return new_head;
}
void odd_even(Node* &head){
    Node* odd=head;
    Node* even=odd->next;
    Node* connect=even;
    //to make odd indices linked list
    while(odd->next/*for odd number of nodes*/ && odd->next->next/*for even number of nodes*/){ //i dont want odd pointer to be at null;
        odd->next=odd->next->next;
        odd=odd->next;
        //to link even indices nodes
        even->next=even->next->next;
        even=even->next;
    }
    odd->next=connect;
}
void reorder(Node* &head){
    if(head==nullptr || head->next==nullptr || head->next->next==nullptr){
        return ;
    }
    Node* slow=head;
    Node* fast=head;
    //finding middle element and breaking connection after that
    do{
        slow=slow->next;
        fast=fast->next->next;
    }while(fast && fast->next);
    Node* temp=slow->next;
    slow->next=nullptr;
    //now we have two linked lists
    //now reverse the second linked list(4->5->6->null)
    //temp is pointing to 4
    Node* previous=nullptr;
    while(temp){
        Node* next_node=temp->next;
        temp->next=previous;
        previous=temp;
        temp=next_node;
    }
    slow=head;
    //1->2->3->null
    //slow is pointing to 1
    //6->5->4->null
    //previous is pointing to 6
    while(previous){
        Node*ptr1=slow->next;
        Node*ptr2=previous->next;
        slow->next=previous;
        slow=ptr1;
        previous->next=slow;
        previous=ptr2;
    }
}
Node* swap_adjacent_nodes(Node* &head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    Node* second_node=head->next;
    //original head end me humara second node bn chuka hoga
    //so hum uske next vaale part ko recursion se call kr re hai
    head->next=swap_adjacent_nodes(second_node->next/*third node se*/);
    second_node->next=head;
    return second_node;
}
int main(){
// //given two linked lists. check if they are equal or not(same data and arrangement)
// //nodes have equal value and length of LL is same
//     LinkedList l1;
//     LinkedList l2;
//     l1.insert_at_end(1);
//     l1.insert_at_end(2);
//     l1.insert_at_end(3);
//     l1.insert_at_end(4);
//     l1.insert_at_end(5);
//     l2.insert_at_end(1);
//     l2.insert_at_end(2);
//     l2.insert_at_end(3);
//     l2.insert_at_end(4);
//     l2.insert_at_end(5);
//     l2.insert_at_end(5);
//     l1.display();
//     l2.display();
//     cout<<check_equal(l1.head,l2.head);
//O(n)

// //given two linked lists. return the node at which two lists intersect. return null if there is no intersection
//     LinkedList l3;//size-m
//     LinkedList l4;//size-n
//     l3.insert_at_end(1);
//     l3.insert_at_end(2);
//     l3.insert_at_end(3);
//     l3.insert_at_end(4);
//     l3.insert_at_end(5);
//     l4.insert_at_end(6);
//     l4.insert_at_end(12);
//     l4.insert_at_end(13);
//     l4.insert_at_end(7);
//     l4.head->next->next->next->next=l3.head->next->next->next;
//     cout<<"Linked list 1:\n";
//     l3.display();
//     cout<<"Linked list 2:\n";
//     l4.display();
//     if(intersection(l3.head,l4.head))
//     cout<<"The intersection node is "<<intersection(l3.head,l4.head)->value;
//     else
//     cout<<"NULL";

// //remove kth node from the end of list and return its head(k<=length of the LL)
//     LinkedList l5;
//     l5.insert_at_end(1);
//     l5.insert_at_end(2);
//     l5.insert_at_end(3);
//     l5.insert_at_end(4);
//     l5.insert_at_end(5);
//     l5.insert_at_end(6);
//     l5.insert_at_end(7);
//     l5.display();
//     remove_from_end(l5.head,5);
//     l5.display();

// //given two sorted linked lists.
// //merge them into single linked list such that resulting list is also sorted .
//     LinkedList l6;
//     l6.insert_at_end(1);
//     l6.insert_at_end(2);
//     l6.insert_at_end(15);
//     l6.insert_at_end(1600);
//     LinkedList l7;
//     l7.insert_at_end(1);
//     l7.insert_at_end(6);
//     l7.insert_at_end(16);
//     l7.insert_at_end(45);
//     l7.insert_at_end(67);
//     l6.display();
//     l7.display();
//     Node* Newhead=merge_sorted(l6.head,l7.head);
//     print(Newhead);

// //there is an array of k sorted linked lists. merge sort into single linked lists and return it
// //hint- merge two linked lists first and then merge it with another and so on....
//     LinkedList l1,l2,l3;
//     int i=1;
//     cout<<"Linked list 1:\n";
//     while(i==1){
//         int n;
//         cout<<"enter the element to be inserted:\t";
//         cin>>n;
//         l1.insert_at_end(n);
//         cout<<"Want to insert an element:\t";
//         cin>>i;
//     }
//     i=1;
//     cout<<"Linked list 2:\n";
//     while(i==1){
//         int n;
//         cout<<"enter the element to be inserted:\t";
//         cin>>n;
//         l2.insert_at_end(n);
//         cout<<"Want to insert an element:\t";
//         cin>>i;
//     }    
//     i=1;
//     cout<<"Linked list 3:\n";
//     while(i==1){
//         int n;
//         cout<<"enter the element to be inserted:\t";
//         cin>>n;
//         l3.insert_at_end(n);
//         cout<<"Want to insert an element:\t";
//         cin>>i;
//     }
//     l1.display();
//     l2.display();
//     l3.display();
//     LinkedList merged;
//     vector<Node*> lists;
//     lists.push_back(l1.head);
//     lists.push_back(l2.head);
//     lists.push_back(l3.head);
//     merged.head=merge_sort_k_LL(lists);
//     merged.display();

// //find middle element of linked list(traversal is allowed only once)
//     LinkedList l;
//     l.insert_at_end(1);
//     l.insert_at_end(2);
//     l.insert_at_end(3);
//     l.insert_at_end(4);
//     l.insert_at_end(5);
//     l.insert_at_end(6);
//     // l.insert_at_end(7);
//     find_middle_ele(l.head);

// //given head of a linked list. determine if it has a cycle in it.
//     LinkedList l;
//     l.insert_at_end(1);
//     l.insert_at_end(2);
//     l.insert_at_end(3);
//     l.insert_at_end(4);
//     l.insert_at_end(5);
//     l.head->next->next->next->next->next=l.head->next->next;//(5->3)
//     // l.display();//will run infinitely
//     cout<<check_cycle(l.head)<<endl;
//     //to remove the cycle
//     remove_cycle(l.head);
//     l.display();

// //given head of the linked list, determine if the linked list is palindrome or not
//     LinkedList l;
//     l.insert_at_end(1);
//     l.insert_at_end(2);
//     l.insert_at_end(3);
//     l.insert_at_end(4);
//     l.insert_at_end(4);
//     l.insert_at_end(3);
//     l.insert_at_end(2);
//     l.insert_at_end(1);
//     l.display();
//     cout<<check_palindrome(l.head);

// //given the head of the linked list. rotate it to right by k places.
//     LinkedList l;
//     l.insert_at_end(1);
//     l.insert_at_end(2);
//     l.insert_at_end(3);
//     l.insert_at_end(4);
//     l.insert_at_end(5);
//     cout<<"original linked list:\t";
//     l.display();
//     int k;
//     cout<<"enter k:\t";
//     cin>>k;
//     cout<<"Rotated linked list:\t";  
//     l.head=rotate_k_steps(l.head,k);
//     l.display();

// //group all nodes with odd indices together followed by nodes with even indices.return the reordered list
//     LinkedList l;
//     l.insert_at_end(1);
//     l.insert_at_end(2);
//     l.insert_at_end(3);
//     l.insert_at_end(4);
//     l.insert_at_end(5);
//     l.insert_at_end(6);
//     cout<<"original linked list:\t";
//     l.display();
//     odd_even(l.head);
//     l.display();

// //given linked list:
// //l0->l1->l2->l3......ln-1->ln
// //group nodes in the following manner:
// //l0->ln->l1->ln-1->l2->ln-2......
//     LinkedList l;
//     l.insert_at_end(1);
//     l.insert_at_end(2);
//     l.insert_at_end(3);
//     l.insert_at_end(4);
//     l.insert_at_end(5);
//     l.insert_at_end(6);
//     l.insert_at_end(7);
//     // l.insert_at_end(8);
//     cout<<"original linked list:\t";
//     l.display();
//     reorder(l.head);
//     l.display();

// //swap every two adjacent nodes
//     LinkedList l;
//     l.insert_at_end(1);
//     l.insert_at_end(2);
//     l.insert_at_end(3);
//     l.insert_at_end(4);
//     l.insert_at_end(5);
//     cout<<"original linked list:\t";
//     l.display();
//     l.head=swap_adjacent_nodes(l.head);
//     l.display();
    return 0;
}