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

int calculate_height(struct Node* root){
    if(root==NULL){
        return 0;
    }
    else{
        int lheight = calculate_height(root->left);
        int rheight = calculate_height(root->right);
        if(lheight>rheight){
            return lheight+1;
        }
        else{
            return rheight+1;
        }
    }
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
    calculate_height(root);
    return 0;
}