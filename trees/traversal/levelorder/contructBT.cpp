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

TreeNode* construct(int arr[],int n){
    queue<TreeNode*>q;
    TreeNode* root = new TreeNode(arr[0]);
    q.push(root);
    int i = 1;
    int j = 2;
    while(q.size()>0 && i<n){
        TreeNode* temp = q.front();
        q.pop();
        TreeNode* l;
        TreeNode* r;
        if(arr[i]!=INT16_MIN) l = new TreeNode(arr[i]);
        else l = NULL;
        if(arr[j]!=INT16_MIN) r = new TreeNode(arr[j]);
        else r = NULL;

        temp->left=l;
        temp->right=r;

        i+=2;
        j+=2;
    }
    return root;
}

int main(){
    TreeNode* root = NULL;
    
    int arr[] = {};
    return 0;
}