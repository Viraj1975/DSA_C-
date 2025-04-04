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

class singlylinkedlist{
    public: 
        Node* head;
        singlylinkedlist(){
            head=NULL;
        }
};

int main(){
    singlylinkedlist sll;
    return 0;
}