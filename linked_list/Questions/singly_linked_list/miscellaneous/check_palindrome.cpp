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
            Node* temp = head;
            while(temp!=NULL){
                cout<<temp->value<<"->";
                temp=temp->next;
            }cout<<"NULL";
        }
};

bool is_Palindrome(Node* head){
    if(!head) return false;
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    Node* curr = slow;
    Node* prev = NULL;
    slow->next=NULL;
    while(curr!=NULL){
        Node* next_node = curr->next;
        curr->next=prev;
        prev=curr;
        curr=next_node;
    }
    Node* head1 = prev;
    Node* head2 = head;
    while(head1){
        if(head1->value!=head2->value){
            return true;
        }
        head1=head1->next;
        head2=head2->next;
    }
    return false;
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
    ll.display();cout<<endl;
    cout<<is_Palindrome(ll.head);
    return 0;
}