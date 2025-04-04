#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int val){
            this->val=val;
            this->left=NULL;
            this->right=NULL;
        }
};

bool isCBT(TreeNode* root){
    if(root==NULL) return true;
    queue<TreeNode*>q;
    q.push(root);
    int count = 0;
    while(q.front()!=NULL){
        TreeNode* temp = q.front();
        q.pop();
        q.push(temp->left);
        q.push(temp->right); 
    }
    while(q.size()>0){
        if(q.front()!=NULL) return false;
        q.pop();
    }
    return true;
}

int main(){

    return 0;
}