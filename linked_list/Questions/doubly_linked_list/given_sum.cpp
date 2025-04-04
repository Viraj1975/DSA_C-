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

void given_sum(Node* &head,Node* &tail,int array[],int sum){
    Node* left = head;
    Node* right = tail;
    while(left!=right && right->next!=left){
        if((left->value+right->value)==sum){
            array[0]=left->value;
            array[1]=right->value;
            return;
        }
        else if((left->value+right->value)>sum){
            right=right->prev;
        }
        else{
            left=left->next;
        }
    }
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
    int array[] = {-1,-1};
    int sum;
    cin>>sum;
    given_sum(dll.head,dll.tail,array,sum);
    cout<<array[0]<<" "<<array[1]<<" ";
    return 0;
}
