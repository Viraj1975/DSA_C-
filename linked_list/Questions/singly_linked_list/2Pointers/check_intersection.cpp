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
            Node* temp=head;
            while(temp!=NULL){
                cout<<temp->value<<"->";
                temp=temp->next;
            }cout<<"NULL";
        }
};

int getlength(Node* head){
    Node* temp = head;
    int length = 0;
    while(temp!=NULL){
        temp=temp->next;
        length++;
    }
    return length;
}

Node* movehead(Node* &head,int shifting_length){
    Node* temp = head;
    int count = 0;
    while(count<shifting_length){
        temp=temp->next;
        count++;
    }
    return temp;
}

Node* getintersection(Node* head1,Node* head2){
    int l1 = getlength(head1);
    int l2 = getlength(head2);
    int shifting_length;
    Node* ptr1;
    Node* ptr2;
    if(l1>l2){
        shifting_length=l1-l2;
        ptr1 = movehead(head1,shifting_length);
        ptr2 = head2;
    }
    else{
        shifting_length=l2-l1;
        ptr2 = movehead(head2,shifting_length);
        ptr1 = head2;
    }
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->next==ptr2->next){
            return ptr1->next;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return NULL;
}

int main(){
    linkedlist ll1;
    linkedlist ll2;
    int n1;
    cin>>n1;
    for(int i=0;i<n1;i++){
        int ele;
        cin>>ele;
        ll1.insertattail(ele);
    }
    ll2.insertattail(6);
    ll2.insertattail(7);
    ll2.head->next->next=ll1.head->next->next->next;
    ll1.display();cout<<endl;
    ll2.display();cout<<endl;
    Node* intersection = getintersection(ll1.head,ll2.head);
    if(intersection){
        cout<<intersection->value;
    }
    else cout<<-1;
    return 0;
}