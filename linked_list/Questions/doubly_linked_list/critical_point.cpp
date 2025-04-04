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

bool is_critical(Node* &curr){
        if(curr->value>curr->next->value && curr->value>curr->prev->value){
            return true;
        }
        if(curr->value<curr->next->value && curr->value<curr->prev->value){
            return true;
        }
        return false;
}

void critical_point(Node* &head,Node* &tail,int array[]){
    Node* curr = tail->prev;
    int k=0;
    int lastCP=-1;
    int firstCP=-1;
    if(curr==NULL){
        array[0]=array[1]=-1;
        return;
    }
    while(curr->next!=NULL){
        if(is_critical){
            if(firstCP==-1){
                firstCP=lastCP=k;
            }
            else{
                array[0]=min(array[0],k-lastCP);
                array[1]=k-firstCP;
                lastCP=k;
            }
        }
        k++;
        curr=curr->prev;
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
    dll.display();cout<<endl;
    critical_point(dll.head,dll.tail,array);
    cout<<array[0]<<" "<<array[1]<<" ";
    return 0;
}
