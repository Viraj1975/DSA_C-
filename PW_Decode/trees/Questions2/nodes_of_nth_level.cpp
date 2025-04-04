#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int val){
            this->val = val;
            this->left = NULL;
            this->right = NULL;
        }
};

TreeNode* insert(TreeNode* root,int ele){
    if(root==NULL){
        root = new TreeNode(ele);
        return root;
    }
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        if(temp->left==NULL){
            temp->left = new TreeNode(ele);
            break;
        }else{
            q.push(temp->left);
        }
        if(temp->right==NULL){
            temp->right = new TreeNode(ele);
            break;
        }else{
            q.push(temp->right);
        }
    }
    return root;
}

void levelOrder(TreeNode* root){
    if(root==NULL) return;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(root->left){
            q.push(root->left);
        }
        if(root->right){
            q.push(root->right);
        }
    }
}

void nthLevel(TreeNode* root,int curr,int level){
    if(root==NULL) return;
    if(curr==level){
        cout<<root->val<<" ";
        return;
    }
    nthLevel(root->left,curr+1,level);
    nthLevel(root->right,curr+1,level);
}

int main(){
    TreeNode* root = NULL;
    int ele;
    while(ele!=-1){
        cin>>ele;
        if(ele==-1){
            break;
        }
        root = insert(root,ele);
    }
    nthLevel(root,1,1); 
    return 0;
}