#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node{
    int value;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->value=data;
    new_node->next=NULL;
    return new_node;
}

void insert_at_end(struct Node** head,struct Node** tail,int value){
    struct Node* new_node = createNode(value);
    if(*head==NULL){
        *head=new_node;
        *tail=new_node;
        return;
    }
    (*tail)->next=new_node;
    (*tail)=new_node;
    new_node->next=*head;
    return;
}

void display(struct Node* head){
    if(head==NULL) return;
    struct Node* temp = head;
    do{
        printf("%d ",temp->value);
        temp=temp->next;
    }while(temp!=head);
    printf("\n");
}

void print_winner(struct Node** head,int M){
    struct Node* ptr1 = *head;
    struct Node* ptr2 = *head;
    while(ptr1->next!=ptr1){
        int count = 1;
        while(count!=M){
            ptr2=ptr1;
            ptr1=ptr1->next;
            count++;
        }
        ptr2->next=ptr1->next;
        struct Node* temp = ptr1;
        ptr1=ptr2->next;
        free(temp);
    }
    *head=ptr1;
}

int main(){
    struct Node* head = NULL;
    struct Node* tail = NULL;
    int N;
    printf("Enter the Number of persons : ");
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        insert_at_end(&head,&tail,i);
    }
    display(head);
    int M;
    printf("Enter the value of M : ");
    scanf("%d",&M);
    print_winner(&head,M);
    display(head);
    return 0;
}