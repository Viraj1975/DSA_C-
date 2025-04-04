#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int value;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int value){
            this->value = value;
            this->left = NULL;
            this->right = NULL;
        } 
};

void TopView(TreeNode* root){
    unordered_map<int,int>m;
    // level , value 

    queue<pair<TreeNode*,int>>q;
    // Node , level 
    q.push({root,0});
    m[0]=root->value;
    while(q.size()>0){
        TreeNode* temp = (q.front()).first;
        int lev = (q.front()).second;
        q.pop();
        if(temp->left){
            q.push({temp->left,lev-1});
            if(m.find(lev-1)==m.end()) m[lev]=temp->left->value;
        } 
        if(temp->right){
            q.push({temp->right,lev+1});
            if(m.find(lev+1)==m.end()) m[lev]=temp->right->value;
        }
    }
    int mx = INT_MIN;
    int mn = INT_MAX;
    for(auto x : m){
        mx = max(mx,x.first);
        mn = min(mn,x.first);
    }
    for(int i=mn;i<=mx;i++){
        cout<<m[i]<<" ";
    }
}

int main(){
    return 0;
}