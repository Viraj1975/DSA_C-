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

int check_identical(struct Node* root1,struct Node* root2){
    if(root1==NULL && root2==NULL){
        return 1;
    }
    else if(root1==NULL || root2==NULL){
        return 0;
    }
    else{
        if(root1->data==root2->data && check_identical(root1->left,root2->left) && check_identical(root1->right,root2->right)){
            return 1;
        }
        else{
            return 0;
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
    struct Node* root1 = create();
    struct Node* root2 = create();
    int result = check_identical(root1,root2);
    return 0;
}