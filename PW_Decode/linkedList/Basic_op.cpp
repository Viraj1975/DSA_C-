#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* next;

        Node(int val){
            this->val=val;
            this->next=NULL;
        }
};

class linkedList{
    public:
        Node* head;
        Node* tail;
        int size;

        linkedList(){
            head=NULL;
            tail=NULL;
            size=0;
        }

        ~linkedList(){
            while(head!=NULL){
                delete_at_start();
            }
        }

        void insert_at_start(int val){
            size++;
            Node* new_Node = new Node(val);
            if(head==NULL){
                head = new_Node;
                tail = new_Node;
                return;
            }
            new_Node->next = head;
            head = new_Node;
        }

        void insert_at_end(int val){
            size++;
            Node* new_Node = new Node(val);
            if(head==NULL || tail==NULL){
                head = new_Node;
                tail = new_Node;
                return;
            }
            tail->next = new_Node;
            tail = new_Node;
        }

        void insert_at_k(int val,int k){
            Node* new_Node = new Node(val);
            if(k>size || k<0) return;
            if(k==0){
                insert_at_start(val);
                return;
            }
            if(k==size){
                insert_at_end(val);
                return;
            }
            size++;
            int count = 0;
            Node* temp1 = head;
            while(count!=k-1){
                temp1=temp1->next;
                count++;
            }
            Node* temp2 = temp1->next;
            temp1->next = new_Node;
            new_Node->next = temp2;
        }

        void delete_at_start(){
            if(head==NULL){
                return;
            }
            size--;
            Node* temp = head;
            head=temp->next;
            if(head==NULL){
                tail=NULL;
            }
            delete temp;
        }

        void delete_at_end(){
            if(head==NULL){
                return;
            }
            size--;
            Node* temp = head;
            if(head==tail){
                head=NULL;
                tail=NULL;
                delete temp;
                return;
            }
            while(temp->next!=tail){
                temp=temp->next;
            }
            Node* tmp = tail;
            tail = temp;
            tail->next=NULL;
            delete tmp;
        }

         void delete_at_k(int k){
            if(k>=size || k<0) return;
            if(k==0){
                delete_at_start();
                return;
            }
            if(k==size-1){
                delete_at_end();
                return;
            }
            size--;
            int count = 0;
            Node* temp1 = head;
            while(count!=k-1){
                temp1=temp1->next;
                count++;
            }
            Node* temp2 = temp1->next;
            temp1->next = temp2->next;
            delete temp2;
        }
        
        void display(){
            Node* temp = head;
            while(temp!=NULL){
                cout<<temp->val<<"->";
                temp = temp->next;
            }
            cout<<"NULL"<<endl;
        }
};

int main(){
    linkedList ll;
    for(int i=0;i<10;i++){
        ll.insert_at_end(i+1);
    }
    // ll.delete_at_start();
    // ll.delete_at_end();
    ll.display();
    ll.insert_at_k(11,10);
    ll.display();
    ll.delete_at_k(10);
    ll.display();
    cout<<ll.size;
    return 0;
}
