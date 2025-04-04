#include<iostream>
using namespace std;

class cir_Node{
    public:
        int value;
        cir_Node* next;
        
        cir_Node(int value){
            this->value = value;
            next = NULL;
        }
};

void insert(cir_Node* root,int value){
    cout<<"visited"<<" ";
    cir_Node* new_Node = new cir_Node(value);
    if(root==NULL){
        new_Node->next = new_Node;
        root = new_Node;
        return;
    }
    cir_Node* temp = root;
    while(temp->next!=temp){
        temp = temp->next;
    }
    temp->next = new_Node;
    new_Node->next = root;
}

void display(cir_Node* root){
    cout<<"Visited ";
    cir_Node* temp = root;
    while(temp->next!=root){
        cout<<temp->value<<" ";
        temp=temp->next;
    }cout<<temp->value;
}

int main(){
    cir_Node* Head = NULL;
    for(int i=0;i<5;i++){
        insert(Head,i);
    }
    display(Head);
    return 0;
}