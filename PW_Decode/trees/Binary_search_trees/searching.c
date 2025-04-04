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
    int x;
    printf("Enter the value : ");
    scanf("%d",&x);
    if(x==-1){
        return NULL;
    }
    printf("Enter the left child of %d : ",x);
    new_node->left = create();
    printf("Enter the right child of %d : ",x);
    new_node->right = create();
    return new_node;
}

struct Node* create_Node(int key){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data=key;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}

struct Node* search(struct Node* root,int key){
    if(root==NULL || root->data==key){
        return root;
    }  
    if(root->data<key){
        search(root->right,key);
    }  
    return search(root->left,key);
}

int main(){
    struct Node* root = create();
    int key;
    printf("Enter the value to be searched : ");
    scanf("%d",&key);
    search(root,key);
    return 0;
}