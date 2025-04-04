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
    if(key<root->data){
        root->left=insert(root->left,key);
    }
    else if(key>root->data){
        root->right=insert(root->right,key);
    }
    else{
        printf("Duplicate key");
    }
    return root;
}

struct Node* delete(struct Node* root,int key){
    if(root==NULL){
       return root;
    }
    if(key>root->data){
        root->right=delete(root->right,key);
        return root;
    }
    else if(key<root->data){
        root->left=delete(root->left,key); 
        return root;
    }
    else{
        if(root->left!=NULL && root->right!=NULL){
            struct Node* temp = root->right;
            while(temp->left!=NULL){
                temp=temp->left;
            }
            root->data=temp->data;
            root->right=delete(root->right,temp->data);
        }
        else{
            struct Node* temp = root;
            if(root->left!=NULL){
                root=root->left;
            }
            else if(root->right!=NULL){
                root=root->right;
            }
            else{
                return NULL;
            }
            free(temp);
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
    struct Node* root = NULL;
    int key;
    root = insert(root,10);
    insert(root,15);
    insert(root,25);
    insert(root,5);
    insert(root,2);
    insert(root,20);
    insert(root,8);
    inorder(root);
    printf("Enter the value to be deleted : ");
    scanf("%d",&key);
    root = delete(root,key);
    inorder(root);
    return 0;
}