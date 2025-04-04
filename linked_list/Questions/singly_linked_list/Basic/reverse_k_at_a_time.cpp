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

        void dispaly(){
            Node* temp = head;
            while(temp!=NULL){
                cout<<temp->value<<"->";
                temp=temp->next;
            }
            cout<<"NULL";
        }
};

Node* reverse_k_at_a_time(Node* &head,int k){
    Node* prev = NULL;
    Node* curr = head;
    int counter = 0;
    while(curr!=NULL && counter<k){
       Node* temp = curr->next;
       curr->next=prev;
       prev=curr;
       curr=temp;
       counter++; 
    }
    if(curr!=NULL) {
        Node* new_head = reverse_k_at_a_time(curr,k);
        head->next=new_head;
    }
    return prev;

}

int main(){
    linkedlist ll;
    int n,k;
    cin>>n;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        ll.insertattail(ele);
    }
    ll.dispaly();
    cout<<endl;
    cin>>k;
    reverse_k_at_a_time(ll.head,k);
    cout<<endl;
    ll.dispaly();
    return 0;
}