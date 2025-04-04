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

Node* swapping_adjacent_Nodes(Node* &head){
    // base case
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* second_node = head->next;
    head->next = swapping_adjacent_Nodes(second_node->next);
    second_node->next=head;
    return second_node;
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
    ll.head = swapping_adjacent_Nodes(ll.head);
    ll.display();cout<<endl;
    return 0;
}

// 1 2 3 4 5 6 

// 1 2 3
// 6 5 4 