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
                cout<<temp->value<<" ";
                temp = temp->next;
            }
        }
};

    void delete_alternate(Node* &head){
        Node* curr = head;
        while(curr!=NULL && curr->next!=NULL){
            Node* temp = curr->next;
            curr->next=temp->next;
            free(temp);
            curr = curr->next;
        }
    }



int main(){
    Node* head = NULL;
    linkedlist ll;
    for(int i=0;i<10;i++){
        ll.insertattail(i);
    }
    ll.display();
    delete_alternate(ll.head);
    cout<<endl;
    ll.display();
    return 0;
}