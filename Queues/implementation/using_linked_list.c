#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct QueueNode{
    int data;
    struct QueueNode* next;
};

struct QueueNode* create_Node(int data){
    struct QueueNode* new_node = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    new_node->data=data;
    new_node->next=NULL;
    return new_node;
}

void Enqueue(struct QueueNode** head,struct QueueNode** tail,int data,int *count,int size){
    struct QueueNode* new_node = create_Node(data);
    if(is_FULL(count,size)){
        printf("Overflow ");
        return;
    }
    if(*head==NULL){
        *head=new_node;
        *tail=new_node;
        (*count)++;
        return;
    }
    (*tail)->next=new_node;
    (*tail)=new_node;
    (*count)++;
    return;
}

int Dequeue(struct QueueNode** head,struct QueueNode** tail,int* count){
    if(is_EMPTY(count)){
        printf("Underflow ");
        return 0;
    }
    int curr = (*head)->data;
    if((*head)->next==NULL){
        (*head)=NULL;
        (*tail)=NULL;
        (*count)--;
        return curr;
    }
    struct QueueNode* temp = *head;
    (*head)=temp->next;
    (*count)--;
    free(temp);
    return curr;
}

int front(struct QueueNode* head){
    if(head==NULL) return INT_MAX;
    return head->data;
}

int is_FULL(int* count,int size){
    if(*count==size) return 1;
    return 0;
}

int is_EMPTY(int* count){
    if(*count==0) return 1;
    return 0;
}

void display(struct QueueNode* head){
    if(head==NULL) return;
    struct QueueNode* temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }printf("\n");
    return;
}

int main(){
    struct QueueNode* head = NULL;
    struct QueueNode* tail = NULL;
    int size;
    int count = 0;
    printf("Enter the size of Queue : ");
    scanf("%d",&size);
    printf("Enter the elements : ");
    for(int i=0;i<size;i++){
        int ele;
        scanf("%d",&ele);
        Enqueue(&head,&tail,ele,&count,size);
    }
    display(head);
    Dequeue(&head,&tail,&count);
    display(head);
    return 0;
}