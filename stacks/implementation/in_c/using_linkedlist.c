#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct stackNode{
    int value;
    struct stackNode* next;
};

struct stackNode* new_Node(int value){
    struct stackNode* stackNode = (struct stackNode*)malloc(sizeof(struct stackNode));
    stackNode->value = value;
    stackNode->next = NULL;
    return stackNode;
};

void push(struct stackNode** head,int value){
    struct stackNode* new_node = new_Node(value);
    new_node->next = (*head);
    (*head) = new_node;
    return;
}

int pop(struct stackNode** head){
    int curr = (*head)->value;
    struct stackNode* node = (*head);
    (*head) = (*head)->next;
    free(node);
    return curr;
}

int is_empty(struct stackNode* head){
    return (!head); 
}

int peak(struct stackNode* head){
    if(is_empty(head)){
        return INT_MIN;
    }
    return head->value;
}

void display(struct stackNode* head){
    struct stackNode* temp = (head);
    while(temp!=NULL){
        printf("%d ",temp->value);
        temp=temp->next;
    }
    return;
}

int main(){
    struct stackNode* head = NULL;
    for(int i=0;i<10;i++){
        push(&head,i);
    }
    display(head);
    return 0;
}