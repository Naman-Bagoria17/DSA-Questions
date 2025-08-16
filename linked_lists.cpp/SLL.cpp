#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int value;
    Node* next;
    Node(int data){
        value=data;
        next=NULL;
    }
};
class LinkedList{
    public:
    Node* head;
    LinkedList(){
        head=NULL;//initially linked list is empty. so head is pointing to null
    }
    void InsertAtEnd(int val){//yaha pe head isliye ni paas kiya qki ye function to linked list ke andar hi hai
        Node* new_node= new Node(val);
        if(head==nullptr){
            head=new_node;//pehle to linked list empty hi thi to ek element insert kra diya
            return;
        }
        Node* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=new_node;
    }
    void print(){//yaha pe head isliye ni paas kiya qki ye function to linked list ke andar hi hai
        Node* temp=head;
        while (temp!=nullptr)
        {
            cout<<temp->value<<"->";
            temp=temp->next;
        }cout<<"NULL"<<endl;  
    }
};
void delete_alt_nodes(Node* &head){
    Node* temp=head;
    while(temp/*for even number of nodes*/ && temp->next/*for odd*/){//dono null ni hone chahiye
        Node* del=temp->next;
        temp->next=del->next;
        temp=temp->next;
        del->next = nullptr;
        free(del);
    }
}
void remove_duplicates(Node* &head){
    if(head==nullptr || head->next==nullptr)
        return ;
    Node*temp=head;
    while (temp->next!=nullptr)
    {
        Node* del=temp->next;
        if(del->value==temp->value){
            temp->next=del->next;
            del->next = nullptr;
            free(del);
        }
        else{
            temp=temp->next;
        } 
    }
    //alternative(two while loops)
    //outer=traversing nodes
    //inner=removing duplicate nodes
    // Node* temp=head;
    // while(temp){
    //     while(temp->next && temp->value==temp->next->value){
    //         Node*del=temp->next;
    //         temp->next=del->next;
    //         free(del);
    //     }
    //     temp=temp->next;//jb duplicate nodes ni milegi to control inner loop se bahar aajayega
    // }    
}
void print_reverse(Node* &head){                 //STACK
                                     //reverse(nullptr)(removed from stack and return; executed)
                                     //|------------------------------|
    if(head==nullptr){               //| reverse(last element)        |
                                     // ______________________________
                                     //| reverse(last second element) |
        return;                      // ______________________________
    }                                //| ......                       |
                                     // ______________________________
    print_reverse(head->next);       //| reverse(first element)       |
                                     // ______________________________
    cout<<head->value<<"->";         //|------------------------------|          
                                     
}
void reverse(Node* &head){
    Node* previous=nullptr;//ye intially head se pehle hai 
                        //and hume reverse krna hai toh head ko null pe point krana hoga
    while(head){
        Node* temp=head;
        head=head->next;
        temp->next=previous;
        previous=temp;
    }
    //abhi head null hogya hai toh use previous pe laana pdega
    head=previous;//previous ab last node pe hai to head jo hai previous vaala bn jayega
}
Node* reverse_using_recursion(Node* &head){//see on notebook
    if(head==nullptr || head->next==nullptr){//jb hum bs ek element pass krenge(i.e. last element)
        return head;
    }
    Node* new_head = reverse_using_recursion(head->next);
    head->next->next=head;
    head->next=nullptr;
    return new_head; 
}
Node* reverse_k_nodes(Node* &head, int k){
    Node* previous=nullptr;
    Node* temp=head;
    int i=1;
    while(temp && i<=k ){//we have to reverse only first k elemets using this loop. rest with recursion
        Node* next=temp->next;
        temp->next=previous;
        previous=temp;
        temp=next;
        i++;
    }
    //now temp is at (k+1)th node
    if(temp!=nullptr){//because it is possible that our linked list has only k elements
        Node* new_head=reverse_k_nodes(temp,k);//ye hoga total-k elements vaali L.L kaa head node
        head->next=new_head;//jo first k elements vaali L.L hai uska head ab new head se connect kr do
    }
    return previous;//ab previous pointer jo puri linked list ka head node hai uspe hoga
}
void insertAtHead(Node* &head,int val/*value to be inserted at head*/){//head is a pointer so its of type Node* and we are taking 
//pass by reference here because we want to do changes in linked list
    // hum ek new node bnayenge first node se pehle aur head pointer ko vaha move kr denge
    Node* new_node= new Node(val);//abhi yaha pe is node ki next field me null hai
    new_node->next=head;// aur hume isko first node ki trf point krana hai
    head=new_node;//humari linked list nayi node se start ho ri hai
}
void insertAtTail(Node* &head,int val){
    Node*temp=head;
    while(temp->next!=nullptr){//jb tk temp null ptr ke pehle vaale node pe ni aata usko move krte raho
        temp=temp->next;
    }
    
    Node* new_node=new Node(val);
    temp->next=new_node;    
}
void insertAtArbitrary(Node* &head,int pos, int val){
    if(pos==0){
        insertAtHead(head,val);
        return;
    }
    Node*temp=head;
    for(int i=1;i<=pos-1;i++){//agr 3 pe insert krna hai to temp pehle 0 se 1 jayega, then 1 se 2.
        temp=temp->next;      //(i.e pos-1 times temp move krega)
    }
    Node* new_node=new Node(val);
    new_node->next=temp->next;
    temp->next=new_node;
}
void update_at_position(Node* &head,int k,int new_val){
    Node* temp=head;
    int current_pos=0;
    while(current_pos!=k){
        temp=temp->next;
        current_pos++;
    }
    temp->value=new_val;
}
void deleting_HeadNode(Node* &head){
    Node* temp=head;
    head=head->next;
    //also free up space that previous head node was occupying
    free(temp);
}
void deleting_TailNode(Node* &head){//2nd last node ko null pe point krwa do
    Node* temp=head;
    if(!temp->next)
        head = nullptr;
    while (temp->next->next!=nullptr)
    {
        temp=temp->next;
    }
    Node* last_node=temp->next;
    temp->next=nullptr;    
    free(last_node);
}
void deletion_at_positon(Node* &head,int pos){//position-1 node ko position+1 node pe point krwana pdega
    if(pos==0){
        deleting_HeadNode(head);
        return;
    }
    Node* temp=head;
    for(int i=1;i<pos;i++){
        temp=temp->next;
    }
    Node* node_to_be_deleted=temp->next;
    temp->next=temp->next->next;
    node_to_be_deleted->next = nullptr;
    free(node_to_be_deleted);
}
void display(Node* head){
    Node* temp=head; //initially pointing to head
    while(temp!=nullptr){
        cout<<temp->value<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    // Node* head=nullptr;

    // insertAtHead(head,1);
    // display(head);
    // insertAtHead(head,2);
    // display(head);
    // insertAtHead(head,3);
    // display(head);
    // insertAtHead(head,4);
    // display(head);
    // insertAtHead(head,5);
    // display(head);
    // insertAtTail(head,6);
    // display(head);
    // int pos,val;
    // cout<<"enter position and value to be inserted: ";
    // cin>>pos>>val;
    // insertAtArbitrary(head,pos,val);
    // display(head);
    // update_at_position(head,3,10);
    // display(head);
    // deleting_HeadNode(head);
    // display(head);
    // deleting_TailNode(head);
    // display(head);
    // deletion_at_positon(head,1);
    // display(head);
    
// //Given the head of the linked list. Delete every alternate element starting from second element
// //1->2->3->4->5(Delete 2 and 4)
//     int input;
//     cout<<"enter 1 to insert an element at head\nenter 0 to quit"<<endl;
//     cin>>input;
//     int size=0;
//     while(input==1){
//         int ele;
//         cout<<"enter element:\t";
//         cin>>ele;
//         insertAtHead(head,ele);
//         size++;
//         cout<<"enter 1 to insert an element at head\nenter 0 to quit"<<endl;
//         cin>>input;
//     }
//     cout<<"Original linked list"<<endl;
//     display(head);
//     Node*del;
//     Node* temp=head;
//     for(int i=0;i<size/2;i++){
//         del=temp->next;
//         temp->next=del->next;
//         temp=temp->next;
//         free(del);
//     }
//     cout<<"New linked list"<<endl;
//     display(head);

// //Alternative(by making a new class)
//     LinkedList l;
//     l.InsertAtEnd(1);
//     l.InsertAtEnd(2);
//     l.InsertAtEnd(3);
//     l.InsertAtEnd(4);
//     l.InsertAtEnd(5);
//     l.InsertAtEnd(6);
//     cout<<"Original linked list:-\n";
//     l.print();
//     delete_alt_nodes(l.head);
//     cout<<"New linked list"<<endl;
//     l.print();

// //Given the head of a sorted linked list. Return the sorted linked list by removing duplicates
//    LinkedList l2;
//    l2.InsertAtEnd(1);
//    l2.InsertAtEnd(1);
//    l2.InsertAtEnd(2);
//    l2.InsertAtEnd(3);
//    l2.InsertAtEnd(4);
//    l2.InsertAtEnd(5);
//    l2.InsertAtEnd(5);
//    l2.InsertAtEnd(5);
//    l2.InsertAtEnd(6);
//    l2.InsertAtEnd(7);
//    l2.InsertAtEnd(8);
//    l2.InsertAtEnd(8);
//    cout<<"Original linked list:-\n";
//    l2.print();
//    remove_duplicates(l2.head);
//    cout<<"New linked list:-\n";
//    l2.print();

// //given the head of singly linked list. just print the reversed linked list(remember you have to not reverse the linked list)
// //we can use recursion here(stack)(LIFO)
//    LinkedList l3;
//    l3.InsertAtEnd(1);
//    l3.InsertAtEnd(2);
//    l3.InsertAtEnd(3);
//    l3.InsertAtEnd(4);
//    l3.InsertAtEnd(5);
//    cout<<"original linked list:-\n";
//    l3.print();
//    print_reverse(l3.head);
//    cout<<"NULL"<<endl;
//    l3.print();//returns original linked list.
    
// //given the head of singly linked list. reverse the linked list and  print it.
//    LinkedList l4;
//    l4.InsertAtEnd(1);
//    l4.InsertAtEnd(2);
//    l4.InsertAtEnd(3);
//    l4.InsertAtEnd(4);
//    l4.InsertAtEnd(5);
//    cout<<"original linked list:-\n";
//    l4.print();
//    reverse(l4.head);
//    l4.print();   

// // //Alternative(using recursion)
//    LinkedList l5;
//    l5.InsertAtEnd(1);
//    l5.InsertAtEnd(2);
//    l5.InsertAtEnd(3);
//    l5.InsertAtEnd(4);
//    l5.InsertAtEnd(5);
//    cout<<"original linked list:-\n";
//    l5.print();
//    l5.head=reverse_using_recursion(l5.head);
//    cout<<"New linked list:-\n";
//    l5.print();   

// // given head of the linked list.reverse the nodes of the list k at time and return the modified list
// // LL: 1->2->3->4->5->6->null
// // k=2
// // (1->2)->(3->4)->(5->6)->null
// // 2->1->4->3->6->5
//    LinkedList l6;
//    l6.InsertAtEnd(1);
//    l6.InsertAtEnd(2);
//    l6.InsertAtEnd(3);
//    l6.InsertAtEnd(4);
//    l6.InsertAtEnd(5);
//    cout<<"original linked list:-\n";
//    l6.print();
//    int k;
//    cout<<"enter k:\t";
//    cin>>k;
//    cout<<"New linked list:-\n";
//    if(k>0){
//    l6.head=reverse_k_nodes(l6.head,k);
//    }
//    l6.print();
   return 0;
} 