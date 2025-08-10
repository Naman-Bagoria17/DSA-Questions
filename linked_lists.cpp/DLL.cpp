#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node* previous;
    Node(int data){
        val=data;
        previous=nullptr;
        next=nullptr;
}
};
class DoublyLinkedList{
    public:
    Node* head;
    Node* tail;
    DoublyLinkedList(){
        head=nullptr;
        tail=nullptr;
    }
    void insert_at_start(int val){//O(1)
        Node* new_node= new Node(val);
        if(head==nullptr){
            head=new_node;
            tail=new_node;
            return;
        }
        new_node->next=head;
        head->previous=new_node;
        head=new_node;//now head will be pointing to new node
        return;
    }
    void insert_at_end(int val){//O(1)
        Node* new_node=new Node(val);
        if(tail==nullptr){
           head=new_node;
           tail=new_node;
           return; 
        }
        new_node->previous=tail;
        tail->next=new_node;
        tail=new_node;
        return;       
    }
    void insert_at_arbitrary(int val,int k){//position is starting from one, //O(n) if we dont know the length
        Node* new_node=new Node(val);
        if(k==1){
            insert_at_start(val);
            return;
        }
        Node* temp=head;
        int i=1;
        while(i<k-1){//if k is 3 then one iteration(from node 1 to 2)
            temp=temp->next;
            i++;
        }
        new_node->next=temp->next;
        temp->next=new_node;
        new_node->previous=temp;
        new_node->next->previous=new_node;

    }
    void delete_at_start(){
        if(head==nullptr){
            return;
        }
        Node* temp=head;
        head=head->next;
        if(head==nullptr){//if linked list has one element
            tail=nullptr;
        }
        else
        head->previous=nullptr;
        free(temp);
    }
    void delete_at_end(){
        if(head==nullptr){
            return;
        }
        Node* temp=tail;
        tail=tail->previous;
        if(tail==nullptr){
            head=nullptr;
        }
        else{
            tail->next=nullptr;
        }
        free(temp);
    }
    void delete_at_arbitray(int k){//O(n) if we dont know the length
        if(k==1){
            delete_at_start();
            return;
        }
        Node* temp=head;
        int i=1;
        while(i<k){//jis node ko delete krna hai us node pe hi chle jana hai
            temp=temp->next;
            i++;
        }
        if(temp->next==nullptr){//if k is equal to length 
            temp->previous->next=nullptr;
        }
        else{
        temp->previous->next=temp->next;
        temp->next->previous=temp->previous;
        }
        free(temp);
    }
    void display(){
        Node* temp=head;
        while(temp!=nullptr){
            cout<<temp->val<<" ";
            temp=temp->next;                
        }
        cout<<endl;
        // //or
        // Node* temp=tail;
        // while(temp!=nullptr){
        //     cout<<temp->val<<"->";
        //     temp=temp->previous;                
        // }
        // cout<<endl;
        
    }
};

bool check_palindrome(Node* head, Node* tail){
    if(head==nullptr || head->next==nullptr){
        return NULL;
    }
    Node* ptr1=head;
    Node* ptr2=tail;
    while(ptr1!=ptr2/*odd*/&& ptr1->previous!=ptr2/*even*/){
        if(ptr1->val!=ptr2->val){
            return false;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->previous;
    }
    return true;
}

void reverse_dll(Node* &head,Node* &tail){//change in linked list
    if(head==nullptr){
        return;
    }
    Node* current=head;
    while(current!=nullptr){
        Node* next_node=current->next;
        current->next=current->previous;
        current->previous=next_node;
        current=next_node;
    }
    swap(head,tail);
    // OR   
    // Node* temp=tail;
    // tail=head;
    // head=temp;
}

void delete_neighbors(Node* head,Node* tail){//head and tail will be remain intact
    if(head==nullptr || head->next==nullptr){
        return;
    }
    Node* current=tail->previous;
    while(current->previous){//until current reaches head
        if(current->next->val==current->previous->val){
            Node* temp=current;
            current->previous->next=current->next;
            current->next->previous=current->previous;
            temp->next = nullptr;
            temp->previous = nullptr;
            free(temp);
        }
        current=current->previous;
    }
}

bool is_critical_point(Node* &current){
    if(((current->val)>(current->next->val) && (current->val)>(current->previous->val)) || ((current->val)<(current->next->val) && (current->val)<(current->previous->val))){
        return true;
    }
    return false;

}
vector<int> Distance_btw_critical_points(Node* head,Node* tail){
    vector<int> ans(2,INT_MAX);//so that if at the end the values remains intact, we can return [-1,-1]
    Node* current=tail->previous;
    int lastCP=-1,firstCP=-1;//lastCP is the critical point jo current critical point mila usse pehle vaala
    if(current==nullptr){//for one node only
        ans[0]=ans[1]=-1;
        return ans;
    }
    int currentpos=0;
    while(current!=head){
        if(is_critical_point(current)==true){
            if(firstCP==-1){//check if it is first critical point.
                firstCP=lastCP=currentpos;
            }
            else{
                ans[0]=min(ans[0],currentpos-lastCP);
                ans[1]=currentpos-firstCP;
                lastCP=currentpos;
            }
        }
        currentpos++;
        current=current->previous;
    }
    if(ans[0]==INT_MAX){//if there are fewer than two Critical pts
        ans[0]=ans[1]=-1;
    }
    return ans;
}

vector<int> target_sum(Node* head, Node* tail, int x){
    vector<int> ans(2,-1);
    while(head!=tail){
        if((head->val+tail->val)==x){
            ans[0]=head->val;
            ans[1]=tail->val;
            break;
        }
        if((head->val+tail->val)<x)
        head=head->next;
        else
        tail=tail->previous;
    }
    return ans;
}
int main(){
    // DoublyLinkedList dll;
    // // dll.insert_at_end(1);
    // // dll.display();
    // // dll.insert_at_end(2);
    // // dll.display();
    // // dll.insert_at_end(3);
    // // dll.display();
    // // dll.insert_at_end(4);
    // // dll.display();
    // // dll.insert_at_arbitrary(7,1);
    // // dll.display();
    // // dll.delete_at_start();
    // // dll.display();
    // // dll.delete_at_end();
    // // dll.display();

    // // delete at arbitrary
    // dll.insert_at_end(1);
    // dll.insert_at_end(2);
    // dll.insert_at_end(3);
    // dll.insert_at_end(4);
    // dll.insert_at_end(5);
    // dll.display();
    // dll.delete_at_arbitray(5);
    // dll.display();

// //check palindrome
//     DoublyLinkedList dll;
//     dll.insert_at_end(1);
//     dll.insert_at_end(2);
//     dll.insert_at_end(3);
//     // dll.insert_at_end(3);
//     dll.insert_at_end(2);
//     dll.insert_at_end(1);
//     dll.display();
//     cout<<check_palindrome(dll.head,dll.tail);

// //reverse the doublylinkedlist
//     DoublyLinkedList dll;
//     dll.insert_at_end(1);
//     dll.insert_at_end(2);
//     dll.insert_at_end(3);
//     dll.insert_at_end(4);
//     dll.insert_at_end(5);
//     dll.display();
//     reverse_dll(dll.head,dll.tail);
//     dll.display();

// //traversing from right to left, delete the nodes whose neighbors have the same value
//     DoublyLinkedList dll;
//     dll.insert_at_end(1);
//     dll.insert_at_end(2);
//     dll.insert_at_end(1);
//     dll.insert_at_end(2);
//     dll.insert_at_end(1);
//     dll.display();
//     delete_neighbors(dll.head,dll.tail);
//     dll.display();

// //finding distance between critical points
//     DoublyLinkedList dll;
//     dll.insert_at_end(1);
//     dll.insert_at_end(5);//CP
//     dll.insert_at_end(2);//CP
//     dll.insert_at_end(3);
//     dll.insert_at_end(4);
//     dll.insert_at_end(6);//CP
//     dll.insert_at_end(3);
//     dll.display();
//     vector<int> ans=Distance_btw_critical_points(dll.head,dll.tail);
//     cout<<"minimum distance: "<<ans[0]<<endl;
//     cout<<"maximum distance: "<<ans[1];

// //find the two nodes whose values sum to given target sum 'x'. 
// //and return array containing values at these nodes.
// //if not present, return [-1,-1]
// //if more than one pair present return any of them.
//     DoublyLinkedList dll;
//     dll.insert_at_end(1);
//     dll.insert_at_end(2);
//     dll.insert_at_end(3);
//     dll.insert_at_end(5);
//     dll.insert_at_end(6);
//     dll.display();
//     int x;
//     cout<<"enter target sum:\t";
//     cin>>x;
//     vector<int> ans=target_sum(dll.head,dll.tail,x);
//     cout<<"["<<ans[0]<<", "<<ans[1]<<"]";
    return 0;
}