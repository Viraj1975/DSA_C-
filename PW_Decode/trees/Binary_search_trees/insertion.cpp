#include<bits/stdc++.h>
using namespace std;

class treeNode{
    public:
        int value;
        treeNode* left;
        treeNode* right;
        treeNode(int value){
            this->value = value;
            left = NULL;
            right = NULL;
        }
};

treeNode* insert(treeNode* root,int value){
    if(root == NULL){
        root = new treeNode(value);
        return root;
    }
    if(root->value>value){
        root->left = insert(root->left,value);
    }
    else if(root->value<value){
        root->right = insert(root->right,value);
    }
    return root;
}

void level_order(treeNode* root){
    queue<treeNode*>q;
    q.push(root);
    treeNode* temp;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        cout<<temp->value<<" ";
        if(temp->left!=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
    } 
}

int main(){
    treeNode* root = NULL;
    int ele = INT16_MAX;
    while(ele!=-1){
        cin>>ele;
        if(ele==-1) break;
        root = insert(root,ele);
    }
    level_order(root);
    return 0;
}