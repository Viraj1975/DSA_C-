#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


struct TreeNode{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

int gcd(int a, int b){
    if(b==0){
        return a;
    }
    return gcd(b, a % b);
}

int maxGCD(struct TreeNode *root){
    if(root==NULL){
        return 0;
    }
    int nodeGCD = root->data;
    if(root->left){
        nodeGCD = gcd(nodeGCD, maxGCD(root->left));
    }
    if(root->right){
        nodeGCD = gcd(nodeGCD, maxGCD(root->right));
    }
    return nodeGCD;
}


struct TreeNode *newNode(int data){
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int main(){
    struct TreeNode *root = newNode(5);
    root->left = newNode(10);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->left->right = newNode(25);
    root->right->left = newNode(30);
    root->right->right = newNode(35);
    printf("Maximum GCD of siblings is : %d\n", maxGCD(root));
    return 0;
}
