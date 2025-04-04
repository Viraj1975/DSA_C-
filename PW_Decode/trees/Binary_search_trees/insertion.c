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
    printf("Enter the left child of %d : ",new_node->data);
    new_node->left = create();
    printf("Enter the right child of %d : ",new_node->right);
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

struct Node* insert(struct Node* root,int key){
    if(root==NULL){
        return create_Node(key);
    }
    if(key>root->data){
        root->right=insert(root->right,key);
    }
    else if(key<root->data){
        root->left=insert(root->left,key); 
    }
    return root;
}

int main(){
    struct Node* root = create();
    int key;
    printf("Enter the value to be inserted : ");
    scanf("%d",&key);
    insert(root,key);
    return 0;
}