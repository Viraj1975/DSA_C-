#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node* prev;

        Node(int val){
            this->val = val;
            this->next = NULL;
            this->prev = NULL;
        }
};

void display(Node* head){
    // displaying ll in both ways using iterative approach;

    // while(head){
    //     cout<<head->val<<" ";
    //     head=head->next;
    // }

    while(head->next) head=head->next;
    while(head){
        cout<<head->val<<" ";
        head=head->prev;
    }

    // displaying ll in both ways using recursive approach;

    // if(!head) return;
    // display(head->next);
    // cout<<head->val<<" ";

    // if(!head) return;
    // cout<<head->val<<" ";
    // display(head->next);
}

int main(){
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);
    a->next=b;
    b->prev=a;b->next=c;
    c->prev=b;c->next=d;
    d->prev=c;d->next=e;
    e->prev=d;
    display(a);
    return 0;
}