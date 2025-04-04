#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct Node{
    int value;
    struct Node* next;
};

struct Node* stackNode(int key){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->value=key;
    new_node->next=NULL;
    return new_node;
}

int is_empty(struct Node* head){
    if(head==NULL) return 1;
    else return 0;
}

void push(struct Node* head,int key){
    struct Node* new_node = stackNode(key); 
    if(head==NULL){
        head=new_node;
    }
    new_node->next=head;
    head=new_node;
    return;
}

struct Node* pop(struct Node* head){
    if(is_empty(head)) return INT_MAX;
    struct Node* temp = head;
    head = temp->next;
    int curr_val = temp->value;
    free(temp);
    return head; 
}


struct TreeNode* create(){
    struct TreeNode* new_node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int value;
    printf("Enter the value : ");
    scanf("%d",&value);
    if(value==-1){
        return NULL;
    }
    new_node->data=value;
    printf("Enter the left child of %d : ",value);
    new_node->left=create();
    printf("Enter the right child of %d : ",value);
    new_node->right=create();
    return new_node;
}

void preorder(struct TreeNode* root,struct Node* head){
    struct TreeNode* ptr = root;
    if(root==NULL){
        return;
    }
    push(head,ptr->data);
    while(is_empty(head)){
        ptr = pop(head);
        printf("%d ",ptr->data);
        if(ptr->right!=NULL)
            push(head,ptr->right->data);
        if(ptr->left!=NULL)
            push(head,ptr->left->data);
    }
    printf("\n");
}

int main(){
    struct TreeNode* root = create();
    struct Node* head = NULL;
    preorder(root,head);
    return 0;
}