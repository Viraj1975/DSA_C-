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

Node* find_mid(Node* &head){

    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* ptr1 = head;
    Node* ptr2 = head;
    while(ptr2->next!=NULL && ptr2!=NULL){
        ptr1=ptr1->next;
        ptr2=ptr2->next->next;
    }
    return ptr1;
}

int main(){
    linkedlist ll;
    int n;
    cout<<"Enter number of elements in linkedlist : ";
    cin>>n;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        ll.insertattail(ele);
    }
    ll.display();
    cout<<endl;
    Node* Middlenode = find_mid(ll.head);
    cout<<Middlenode->value;
    return 0;
}