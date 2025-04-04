#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node{
    int data;
    int priority;
    struct Node* next;
};

void enqueue(int key,int priority,struct Node** head){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data=key;
    new_node->priority=priority;
    new_node->next=NULL;
    if((*head)==NULL){
        (*head)=new_node;
        return;
    }
    struct Node* temp = (*head);
    if(temp->priority<new_node->priority){
        new_node->next=(*head);
        (*head)=new_node;
    }
    else{
        while(temp->next!=NULL && temp->next->priority>new_node->priority){
            temp=temp->next;
        }
        struct Node* temp1 = temp->next;
        temp->next=new_node;
        new_node->next=temp1;
    }
}

void dequeue(struct Node** head){
    if((*head)==NULL){
        return;
    }
    struct Node* temp = (*head);
    (*head) = temp->next;
    free(temp);
    return;
}

int is_Empty(struct Node* head){
    return (head==NULL);
}

int peek(struct Node* head){
    return head->data;
}

int main(){
    struct Node* head = NULL;
    enqueue(4,1,&head);
    enqueue(6,4,&head);
    enqueue(5,3,&head);
    enqueue(7,0,&head);
    while(!is_Empty(head)){
        printf("%d ",peek(head));
        dequeue(&head);
    }
    return 0;
}