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
                temp = temp->next;
            }
            temp->next=new_node;
        }

        void display(){
            Node* temp = head;
            while(temp!=NULL){
                cout<<temp->value<<"->";
                temp=temp->next;
            }cout<<"NULL";
        }
};

void reverse_linked_list(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    while(curr!=NULL){
        Node* temp = curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    head=prev;
}

int main(){
    linkedlist ll;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        ll.insertattail(ele);
    }
    ll.display();
    cout<<endl;
    reverse_linked_list(ll.head);
    ll.display();
    return 0;
}