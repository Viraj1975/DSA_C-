#include<iostream>
using namespace std;

class treeNode{
    public:
        int value;
        treeNode* left;
        treeNode* right;

        treeNode(){
            left=NULL;
            right=NULL;
        }
};

bool isCBT(treeNode* Node,int count,int i){
    if(Node==NULL) return true;
    int LC = 2*i+1;
    int RC = 2*i+2;
    if(i>count){
        return false; 
    }
    else{
        bool left = isCBT(Node->left,count,LC);
        bool right = isCBT(Node->right,count,RC);
        return (left && right);
    }
}

bool Is_MaxOrder(treeNode* node){
    if(node->left==NULL && node->right==NULL){
        return true;
    }
    if(node->right == NULL){
        return node->value>node->left->value;
    }
    else{
        bool left = Is_MaxOrder(node->left);
        bool right = Is_MaxOrder(node->right);
        return (left && right && (node->value>node->left->value && node->value>node->right->value));
    }
}

int main(){
    return 0;
}