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

int main(){
    printf("Enter the value of root : ");
    struct Node* root = create();
    inorder(root);
    return 0;
}