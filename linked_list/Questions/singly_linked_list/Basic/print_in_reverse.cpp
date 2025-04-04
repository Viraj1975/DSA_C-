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

class linkedlist{
    public:
        Node* head;
        linkedlist(){
            head = NULL;
        }
        void insertattail(int value){
            Node* new_node = new Node(value);
            Node* temp = head;
            if(head==NULL){
                head=new_node;
                return;
            }
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

void print_reverse(Node* &head){
    if(head==NULL) return;
    print_reverse(head->next);
    cout<<head->value<<" ";
}

int main(){
    linkedlist ll;
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int ele;
        cin>>ele;
        ll.insertattail(ele);
    }
    ll.display();
    cout<<endl;
    print_reverse(ll.head);
    return 0;
}