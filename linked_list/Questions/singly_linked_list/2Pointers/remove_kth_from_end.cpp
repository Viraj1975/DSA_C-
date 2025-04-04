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

void remove_kth_from_end(Node* &head,int k){
    Node* ptr1 = head;
    Node* ptr2 = head;
    while(k--){
        ptr2=ptr2->next;
    }

    if(ptr2==NULL){
        Node* temp = head;
        head=head->next;
        delete temp;
        return;
    }
    while(ptr2->next!=NULL){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }

    Node* temp = ptr1->next;
    ptr1->next=temp->next;
    delete(temp);
    return;
}

int main(){
    linkedlist ll;
    int n;
    cout<<"Enter number of elements in linkedlist : ";
    cin>>n;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        ll.insertattail(ele);
    }
    int k;
    cin>>k;
    ll.display();
    remove_kth_from_end(ll.head,k);
    cout<<endl;
    ll.display();
    return 0;
}