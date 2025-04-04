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

bool check_palindrome(Node* &head,Node* &tail){
    Node* ptr1 = head;
    Node* ptr2 = tail;
    while(ptr1!=ptr2 && ptr2->next!=ptr1){
        if(ptr1->value!=ptr2->value) return false;
        ptr1=ptr1->next;
        ptr2=ptr2->prev;
    }
    return true;
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
    cout<<check_palindrome(dll.head,dll.tail);
    return 0;
}