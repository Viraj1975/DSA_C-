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
    printf("Enter the data : ");
    scanf("%d",&x);
    if(x==-1){
        return NULL;
    }
    new_node->data=x;
    printf("Enter the left child of %d : ",x);
    new_node->left = create();
    printf("Enter the right child of %d : ",x);
    new_node->right = create();
    return new_node;
}

int find_height(struct Node* root){
    if(root==NULL){
        return 0;
    }
    else{
        int lheight = find_height(root->left);
        int rheight = find_height(root->right);
       
       return (lheight>rheight)?lheight+1:rheight+1;
    }
}

void print_level(struct Node* root,int level){
    if(root==NULL){
        return;
    }
    if(level==1){
        printf("%d ",root->data);
        return;
    }
    else if(level>1){
        print_level(root->left,level-1);
        print_level(root->right,level-1);
    }
    return;
}

int main(){
    struct Node* root = create();
    int height = find_height(root);
    for(int i = 1 ; i <= height ; i++){
        print_level(root,i);
    }
    return 0;
}