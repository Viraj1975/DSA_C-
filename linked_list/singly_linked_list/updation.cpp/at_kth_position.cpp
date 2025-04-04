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

void insertathead(Node* &head,int val){
    Node* new_node = new Node(val);
    new_node->next=head;
    head=new_node;
}

void updateatK(Node* &head,int value,int k){
    Node* temp = head;
    int curr_pos=0;
    while(curr_pos!=k){
        temp=temp->next;
        curr_pos++;
    }
    temp->value=value;
}

void display(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->value<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Node* head=NULL;
    insertathead(head,2);
    insertathead(head,1);
    insertathead(head,3);
    insertathead(head,4);
    insertathead(head,5);
    updateatK(head,6,3);
    display(head);
    return 0;
}