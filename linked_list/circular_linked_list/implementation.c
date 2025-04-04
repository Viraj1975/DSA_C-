#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node{
    int value;
    struct Node* next;
};

void insert_at_end(struct Node** head,int value){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->value=value;
    new_node->next=(*head);
    if(*head==NULL){
        new_node->next=new_node;
        *head=new_node;
        return;
    }
    else{
        struct Node* temp = (*head);
        while(temp->next!=(*head)){
            temp=temp->next;
        }
        temp->next=new_node;
    }
    (*head)=new_node;
    return;
}

void display(struct Node* head){
    if(head==NULL) return;
    struct Node* temp = head->next;
    do{
        printf("%d ",temp->value);
        temp=temp->next;
    }while(temp!=head->next);
    printf("\n");
}

int main(){
    struct Node* head = NULL;
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        insert_at_end(&head,i);
    }
    display(head);
    return 0;
}