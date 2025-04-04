#include<iostream>
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

bool check_linkedlist(Node* head1,Node* head2){
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->value != ptr2->value){
            return false;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return (ptr1==NULL && ptr2==NULL);
}

int main(){
    linkedlist ll1;
    linkedlist ll2;
    int n1,n2;
    cin>>n1>>n2;
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
    if(!check_linkedlist(ll1.head,ll2.head)) cout<<"No";
    else cout<<"Yes";
    return 0;
}