#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct stackNode{
    int value;
    struct stackNode* next;
    int size;
};

struct stackNode* createNode(int data){
    struct stackNode* new_node = (struct stackNode*)malloc(sizeof(struct stackNode));
    new_node->value=data;
    new_node->next=NULL;
    return new_node;
}

int is_empty(struct stackNode* head){
    if(head==NULL) return 1;
    return 0;
}

void push(struct stackNode** head,int data){
    struct stackNode* new_node = createNode(data);
    if(*head==NULL){
        *head=new_node;
        (*head)->size++;
        return;
    }
    new_node->next=*head;
    *head=new_node;
    (*head)->size++;
    return;
}

int pop(struct stackNode** head){
    struct stackNode* temp = *head;
    if(temp==NULL || temp->next==NULL){
        int curr = temp->value;
        (*head)->size--;
        free(temp);
        return curr;
    }
    int curr = temp->value;
    *head=temp->next;
    (*head)->size--;
    free(temp);
    return curr;
}

int peak(struct stackNode* head){
    if(is_empty(head)){
        return INT_MAX;
    }
    int curr = head->value;
    return curr;
}

void postfix_evaluation(struct stackNode** head,char string[]){
    
}