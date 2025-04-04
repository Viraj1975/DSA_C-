#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node{
    int row;
    int column;
    int value;
    struct Node* next;
};

struct Node* create_Node(int row,int column,int value){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->row=row;
    new_node->column=column;
    new_node->value=value;
    new_node->next=NULL;
    return new_node;
}

void insert_at_end(struct Node** head,int row,int column,int value){
    struct Node* new_node = create_Node(row,column,value);
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
    struct Node* temp1 = head;
    struct Node* temp2 = head;
    struct Node* temp3 = head;
    printf("Row : ");
    while(temp1!=NULL){
        printf("%d ",temp1->row);
        temp1=temp1->next;
    }
    printf("\n");

    printf("Column : ");
    while(temp2!=NULL){
        printf("%d ",temp2->column);
        temp2=temp2->next;
    }
    printf("\n");

    printf("Value : ");
    while(temp3!=NULL){
        printf("%d ",temp3->value);
        temp3=temp3->next;
    }
    printf("\n");
    return;
}

int main(){
    struct Node* head = NULL;
    int row,column;
    printf("Enter the number of rows and columns : ");
    scanf("%d %d",&row,&column);
    int sparseMatrix[row][column];
    printf("Enter the elements of the sparse Matrix : ");
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            scanf("%d",&sparseMatrix[i][j]);
        }
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            if(sparseMatrix[i][j]!=0){
                int value = sparseMatrix[i][j];
                insert_at_end(&head,i,j,value);
            }
        }
    }
    display(head);
    return 0;
}