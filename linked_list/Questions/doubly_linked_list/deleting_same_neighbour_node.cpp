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
            }
        }
};

void delete_same_neighbour_node(Node* &head,Node* &tail){
    Node* curr = tail->prev;
    while(curr!=NULL){
        Node* nextptr = curr->next;
        Node* prevptr = curr->prev;
        if(nextptr->value==prevptr->value){
            prevptr->next=nextptr;
            nextptr->prev=prevptr;
            delete curr;
        }
        curr=prevptr;
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
    delete_same_neighbour_node(dll.head,dll.tail);
    dll.display();cout<<endl;
    return 0;
}
