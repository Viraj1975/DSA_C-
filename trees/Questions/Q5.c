#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* create(){
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    int x;
    printf("Enter the value : ");
    scanf("%d",&x);
    if(x==-1){
        return NULL;
    }
    root->data=x;
    printf("Enter the value of left child of %d : ",x);
    root->left=create(root->left);
    printf("Enter the value of right child of %d : ",x);
    root->right=create(root->right);
    return root;
}

void inorder(struct Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void max_in_level(struct Node* root){
    if(root==NULL){
        return;
    }
    int front=-1;
    int rear=-1;
    struct Node* queue[1000];
    queue[++rear]=root;
    while(front!=rear){
        int levelsize = front-rear;
        int levelMax = INT_MIN;
        for(int i=0;i<levelsize;i++){
            struct Node* current = queue[++front];
            if(current->data>levelMax){
                levelMax=current->data;
            }
            if(current->left){
                queue[++rear]=current->left;
            }
            if(current->right){
                queue[++rear]=current->right;
            }
        }
        printf("Max element in %d level is %d.",front,levelMax);
    }
}

int main(){
    printf("Enter the value of root : ");
    struct Node* root = create();
    max_in_level(root);
    inorder(root);
    return 0;
}