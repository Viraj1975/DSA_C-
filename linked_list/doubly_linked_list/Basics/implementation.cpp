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
};

int main(){
    Doublylinkedlist dll;
    Node* new_node = new Node(3);
    dll.head=new_node;
    dll.tail=new_node;
    return 0;
}

