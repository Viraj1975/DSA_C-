#include<iostream>
#include<vector>
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

class linkedlist{
    public:
        Node* head;
        linkedlist(){
            head=NULL;
        }
        
        void insertattail(int value){
            Node* new_node = new Node(value);
            if(head==NULL){
                head=new_node;
                return;
            }
            Node* temp = head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=new_node;
        }
        
        void display(){
            Node* temp=head;
            while(temp!=NULL){
                cout<<temp->value<<"->";
                temp=temp->next;
            }cout<<"NULL";
        }
};

Node* merge_sorted_linkedlist(Node* head1,Node* head2){
    Node* Dummy_head=new Node(-1);
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    Node* ptr3 = Dummy_head;
    while(ptr1 && ptr2){
        if(ptr1->value < ptr2->value){
            ptr3->next=ptr1;
            ptr1=ptr1->next;
            ptr3=ptr3->next;
        }
        else{
            ptr3->next=ptr2;
            ptr3=ptr3->next;
            ptr2=ptr2->next;
        }
    }
    while(ptr1){
        ptr3->next=ptr1;
        ptr1=ptr1->next;
        ptr3=ptr3->next;
    }
    while(ptr2){
        ptr3->next=ptr2;
        ptr2=ptr2->next;
        ptr3=ptr3->next;
    }
    return Dummy_head->next;
}

Node* merge_k_sorted_linkedlist(vector<Node*>&list){
    if(list.size()==0) return NULL;
    while(list.size()>1){
        Node* merged_head = merge_sorted_linkedlist(list[0],list[1]);
        list.push_back(merged_head);
        list.erase(list.begin());
        list.erase(list.begin());
    }
    return list[0];
}

int main(){
    linkedlist ll1;
    linkedlist ll2;
    linkedlist ll3;
    linkedlist ll4;
    linkedlist merged_ll;
    int n1,n2,n3,n4;
    cin>>n1>>n2>>n3>>n4;
    for(int i=0;i<n1;i++){
        int ele;
        cin>>ele;
        ll1.insertattail(ele);
    }
    for(int i=0;i<n2;i++){
        int ele;
        cin>>ele;
        ll2.insertattail(ele);
    }
    for(int i=0;i<n3;i++){
        int ele;
        cin>>ele;
        ll3.insertattail(ele);
    }
    for(int i=0;i<n4;i++){
        int ele;
        cin>>ele;
        ll4.insertattail(ele);
    }
    vector<Node*>list = {ll1.head,ll2.head,ll3.head,ll4.head};
    merged_ll.head = merge_k_sorted_linkedlist(list);
    cout<<"After merging and sorting :";
    merged_ll.display();cout<<endl;
    return 0;
}