#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* insert(struct Node* root,int key){
    if(root==NULL){
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data=key;
        new_node->left=NULL;
        new_node->right=NULL;
        return new_node;
    }
    if(key>root->data){
        root->right = insert(root->right,key);
    }
    else if(key<root->data){
        root->left = insert(root->left,key);
    }
    else{
        printf("Duplicate elements not allowed ");
    }
    return root;
}

struct Node* delete(struct Node* root,int key){
    if(root==NULL){
        return root;
    }
    if(key<root->data){
        root->left = delete(root->left,key);
    }
    else if(key>root->data){
        root->right = delete(root->right,key);
    }
    else{
        if(root->left==NULL){
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        else{
            struct Node* temp = root->right;
            while(temp->left!=NULL){
                temp=temp->left;
            }
            root->data=temp->data;
            root->right = delete(root->right,temp->data);
        }
    }
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
    struct Node* root = NULL;
    root = insert(root,5);
    insert(root,3);
    insert(root,2);
    insert(root,4);
    insert(root,7);
    insert(root,6);
    insert(root,8);
    inorder(root);
    int key;
    printf("\nEnter the value to be deleted : ");
    scanf("%d",&key);
    root = delete(root,key);
    inorder(root);
    return 0;
}