#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define Max_Q_size 500 

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* create(){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    int x;
    printf("Enter the data : ");
    scanf("%d",&x);
    if(x==-1){
        return NULL;
    }
    new_node->data=x;
    printf("Enter the left child of %d : ",x);
    new_node->left=create();
    printf("Enter the right child of %d : ",x);
    new_node->right=create();
    return new_node;
}

struct Node** create_queue(int* front,int* rear){
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*)*Max_Q_size);
    *front = *rear = 0;
    return queue;
}

void Enqueue(struct Node* new_node,int* rear,struct Node** queue){
    queue[*rear++]=new_node;
}
struct Node* Dequeue(int* front,struct Node** queue){
    (*front)++;
    return queue[*front-1];
}

void level_order_traversal(struct Node* root){
    int rear,front;
    struct Node** queue = create_queue(&front,&rear);
    struct Node* temp = root;
    while(temp){
        printf("%d ",temp->data);
        if(temp->left){
            Enqueue(temp->left,&rear,queue);
        }
        if(temp->right){
            Enqueue(temp->right,&rear,queue);
        }
        temp = Dequeue(&front,queue);
    }
}

int main(){
    struct Node* root = create();
    printf("Level order traversal : ");
    level_order_traversal(root);
    return 0;
}