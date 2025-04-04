#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* create(){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    int value;
    printf("Enter the value : ");
    scanf("%d ",&value);
    if(value==-1){
        return NULL;
    }
    new_node->data=value;
    printf("Enter the left child of %d : ",value);
    new_node->left=create();
    printf("Enter the right child of %d : ",value);
    new_node->right=create();
    return new_node;
};

void postorder(struct Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main(){
    struct Node* root;
    root = create();
    postorder(root);
    return 0;
}