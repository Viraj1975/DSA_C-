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

void delete_duplicates(Node* &head){
    Node* current_node = head;
    while(current_node->next!=NULL){
        if(current_node->next->value==current_node->value){
            Node* temp = current_node->next;
            current_node->next=temp->next;
            delete temp; 
        }
        else current_node=current_node->next;
    }
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
    delete_duplicates(ll.head);
    cout<<endl;
    ll.display();
    return 0;
}