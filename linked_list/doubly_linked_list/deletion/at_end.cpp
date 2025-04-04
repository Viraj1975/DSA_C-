#include<iostream>
using namespace std;

class Node{
    public:
        int value;
        Node* next;
        Node* prev;
        Node(int data){
            value=data;
            next=NULL;
            prev=NULL;
        }
};

class Doublylinkedlist{
    public:
        Node* head;
        Node* tail;
        Doublylinkedlist(){
            head=NULL;
            tail=NULL;
        }

        void insertathead(int value){
            Node* new_node = new Node(value);
            if(head==NULL){
                head=new_node;
                tail=new_node;
                return;
            }
            new_node->next=head;
            head->prev=new_node;
            head=new_node;
            
        }

        void display(){
            Node* temp = head;
            while(temp!=NULL){
                cout<<temp->value<<" ";
                temp=temp->next;
            }cout<<endl;
        }
};

void delete_tail(Node* &tail,Node* &head){
    if(tail==NULL) return;
    Node* temp = tail;
    if(tail->prev==NULL){
       tail=NULL;
       head=NULL;
       return; 
    }
    else{
        tail=tail->prev;
        tail->next=NULL;
        delete temp;
    }
}

int main(){
    Doublylinkedlist dll;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        dll.insertathead(ele);
    }
    dll.display();cout<<endl;
    delete_tail(dll.tail,dll.head);
    dll.display();cout<<endl;
    return 0;
}
