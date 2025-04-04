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

class queue{
    public:
        Node* head;
        queue(){
            this->head=NULL;
        }

        bool isEmpty(){
            if(head==NULL){
                return true;
            }
            return false;
        }

        int top_element(){
            return head->value;
        }

        void Enqueue(int value){
            Node* newNode = new Node(value);
            if(head==NULL){
                head=newNode;
                return;
            }
            Node* temp = head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
        }

        int DeQueue(){
            if(head==NULL){
                return INT16_MAX;
            }
            int value = head->value;
            Node* temp = head;
            head = temp->next;
            delete(temp); 
            return value;
        }

        void display(){
            Node* temp = head;
            while(temp!=NULL){
                cout<<temp->value<<" ";
                temp=temp->next;
            }
            cout<<"\n";
        }
};

int main(){
    int n;
    cin>>n;
    queue q;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        q.Enqueue(ele);
    }
    q.display();
    q.DeQueue();
    q.display();
    q.DeQueue();
    q.display();
    return 0;
}