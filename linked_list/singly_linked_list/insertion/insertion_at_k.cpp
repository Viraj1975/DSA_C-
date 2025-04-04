#include<iostream>
using namespace std;

class Node{
    public:
        int value;
        Node* next;
        Node(int data){
            value = data;
            next = NULL;
        }
};

void insertat_k(Node* &head,int value1,int k){
    Node* new_node = new Node(value1);
    Node* prev = head;
    int curr_pos=0;
    while(curr_pos!=k-1){
        prev=prev->next;
        curr_pos++;
    }
    Node* prev1 = prev->next;
    prev->next=new_node;
    new_node->next=prev1;
}

void insertathead(Node* &head,int value){
    Node* new_node = new Node(value);
    new_node->next=head;
    head=new_node;
}

void display(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->value<<" ";
        temp = temp->next;
    }
}

int main(){
    Node* head = NULL;
    insertathead(head,1);
    insertathead(head,2);
    insertathead(head,3);
    insertathead(head,4);
    insertathead(head,6);
    insertat_k(head,5,2);
    display(head);
    return 0;
}