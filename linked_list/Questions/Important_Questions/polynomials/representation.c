#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node{
    int power;
    int coeff;
    struct Node* next;
};

void insert_at_tail(struct Node** head ,int power,int coeff){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->power=power;
    new_node->coeff=coeff;
    new_node->next=NULL;
    if((*head)==NULL){
        (*head)=new_node;
        return;
    }
    struct Node* temp = (*head);
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
    return;
}

void display(struct Node* head){
    struct Node* temp = (head);
    while(temp->next!=NULL){
        printf("%dx^%d + ",temp->coeff,temp->power);
        temp=temp->next;
    }
    printf("%dx^%d",temp->coeff,temp->power);
    temp=temp->next;
    printf("\n");
}

int main(){
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    int size1,size2;
    printf("Enter the size of first polynomial : ");
    scanf("%d",&size1);
    printf("Enter the coefficients and powers respectively of the first polynomial : ");
    for(int i=0;i<size1;i++){
        int power;
        int coeff;
        scanf("%d %d",&coeff,&power);
        insert_at_tail(&head1,power,coeff);

    }

    printf("Enter the size of second polynomial : ");
    scanf("%d",&size1);
    printf("Enter the coefficients and powers respectively of the second polynomial : ");
    for(int i=0;i<size1;i++){
        int power;
        int coeff;
        scanf("%d %d",&coeff,&power);
        insert_at_tail(&head2,power,coeff);

    }
    display(head1);
    display(head2);
    return 0;
}