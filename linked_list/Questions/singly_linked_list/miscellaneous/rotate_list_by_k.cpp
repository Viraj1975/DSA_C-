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
            Node* temp = head;
            while(temp!=NULL){
                cout<<temp->value<<"->";
                temp=temp->next;
            }cout<<"NULL";
        }
};

void rotate_list_by_k(Node* &head,int k){
    Node* tail = head;
    int length = 1;
    while(tail->next!=NULL){
        tail=tail->next;
        length++;
    }
    k=k%length;
    if(k==0) return;
    Node* temp = head;
    int distance = length-k-1;
    while(distance--){
        temp=temp->next;
    }
    Node* new_head = temp->next;
    tail->next=head;
    temp->next=NULL;
    head=new_head;
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
    int k;
    cin>>k;
    rotate_list_by_k(ll.head,k);
    ll.display();
    return 0;
}


// 1 2 3 4 5 6 NULL