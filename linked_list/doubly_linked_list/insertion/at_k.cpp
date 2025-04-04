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

        void insertat_k(int value,int k){
            Node* new_node = new Node(value);
            Node* temp = head;
            int count = k-1;
            while(count--){
                temp=temp->next;
            }
            new_node->next=temp->next;
            temp->next=new_node;
            new_node->prev=temp;
            new_node->next->prev=new_node;

        }

        void display(){
            Node* temp = head;
            while(temp!=NULL){
                cout<<temp->value<<" ";
                temp=temp->next;
            }
        }
};

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
    int k,val;
    cin>>k>>val;
    dll.insertat_k(val,k);
    dll.display();cout<<endl;
    return 0;
}
