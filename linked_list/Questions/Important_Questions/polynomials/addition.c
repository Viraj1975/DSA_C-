#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node{
    int power;
    int coeff;
    struct Node* next;
};

struct Node* create_Node(int coeff,int power){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->coeff=coeff;
    new_node->power=power;
    new_node->next=NULL;
    return new_node;
}

void insert_at_end(struct Node** head,int coeff,int power){
    struct Node* new_node = create_Node(coeff,power);
    if(*head==NULL){
        *head=new_node;
        return;
    }
    struct Node* temp = *head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
    return;
}

void display(struct Node* head){
    struct Node* temp = head;
    while(temp->next!=NULL){
        printf("%dx^%d + ",temp->coeff,temp->power);
        temp=temp->next;
    }printf("%dx^%d",temp->coeff,temp->power);
    temp=temp->next;
    printf("\n");
    return;
}

void add_polynomials(struct Node* head1,struct Node* head2,struct Node** head3){
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;
    while(temp1 && temp2){
        if(temp1->power>temp2->power){
            insert_at_end(head3,temp1->coeff,temp1->power);
            temp1=temp1->next;
        }
        else if(temp1->power==temp2->power){
            int coeff = temp1->coeff + temp2->coeff;
            insert_at_end(head3,coeff,temp1->power);
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else{
            insert_at_end(head3,temp2->coeff,temp2->power);
            temp2=temp2->next;
        }
    }
    while(temp1){
        struct Node* new_node;
        new_node = create_Node(temp1->coeff,temp1->power);
        if(*head3==NULL){
            *head3=new_node;
        }
        struct Node* temp = *head3;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }
    while(temp2){
        struct Node* new_node;
        new_node = create_Node(temp2->coeff,temp2->coeff); 
        if(*head3==NULL){
            *head3==new_node;         
        }
        struct Node* temp = *head3;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }
    return;
}

int main(){
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    struct Node* head3 = NULL;
    int size1,size2;
    int power,coeff;
    printf("Enter the size of first polynomial : ");
    scanf("%d",&size1);
    printf("Enter the coefficient and power respectively of first polynomial : ");
    for(int i=0;i<size1;i++){
        scanf("%d %d",&coeff,&power);
        insert_at_end(&head1,coeff,power);
    }
    printf("Enter the size of second polynomial : ");
    scanf("%d",&size2);
    printf("Enter the coefficient and power respectively of second polynomial : ");
    for(int i=0;i<size2;i++){
        scanf("%d %d",&coeff,&power);
        insert_at_end(&head2,coeff,power);
    }
    display(head1);
    display(head2);
    add_polynomials(head1,head2,&head3);
    printf("After addition : ");
    display(head3);
    return 0;
}