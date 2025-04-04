#include<iostream>
using namespace std;

class Node{
    public:
        int value;
        Node* next;
        Node(int value){
            this->value=value;
            next=NULL;
        }
};

class singlyLinkedlist{
    public:
        Node* head;
        singlyLinkedlist(){
            head=NULL;
        }

        void insert_at_tail(int value){
            Node* newNode = new Node(value);
            if(head==NULL){
                head=newNode;
                return;
            }
            Node* temp = head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next = newNode;
        }

        void display(){
            Node* temp = head;
            while(temp!=NULL){
                cout<<temp->value<<"->";
                temp=temp->next;
            }
            cout<<"NULL";
        }
};

int main(){
    int n;
    cin>>n;
    singlyLinkedlist sll;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        sll.insert_at_tail(ele);
    }
    sll.display();
    return 0;
}