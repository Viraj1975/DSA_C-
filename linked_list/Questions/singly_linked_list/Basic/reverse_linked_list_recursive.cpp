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
                temp = temp->next;
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

Node* reverse_linked_list(Node* &head){
    if(head==NULL || head->next==NULL){        
        return head;
    }
    Node* new_head = reverse_linked_list(head->next);
    head->next->next=head;
    head->next=NULL;
    return new_head;
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
    ll.display();
    cout<<endl;
    ll.head = reverse_linked_list(ll.head);
    ll.display();
    return 0;
}