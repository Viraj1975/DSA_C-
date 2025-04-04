#include<bits/stdc++.h>
using namespace std;

class treeNode{
    public:
        int value;
        treeNode* left;
        treeNode* right;
        treeNode(int value){
            this->value = value;
            this->left = NULL;
            this->right = NULL;
        }
};

treeNode* insert(treeNode* root,int ele){
    if(root==NULL){
        root = new treeNode(ele);
        return root;
    }
    if(ele>root->value){
        root->right = insert(root->right,ele);
    }
    else if(ele<root->value){
        root->left = insert(root->left,ele);
    }
    return root;
}

treeNode* deletion(treeNode* root,int ele){
    if(root==nullptr){
        return nullptr;
    }
    if(root->value>ele){
        root->left = deletion(root->left,ele);
        return root;
    }
    else if(root->value<ele){
        root->right = deletion(root->right,ele);
        return root;
    }
    else{
        if(root->right==nullptr || root->left==nullptr){
            treeNode* temp = root;
            if(root->right!=nullptr){
                root = root->right;
            }
            else if(root->left!=nullptr){
                root = root->left;
            }
            else{
                return nullptr;
            }
            delete temp;
        }
        else{
            treeNode* temp = root->right;
            while(temp->left!=nullptr){
                temp=temp->left;
            }
            root->value=temp->value;
            root->right = deletion(root->right,temp->value);
        }
    }
    return root;
}

void level_order_traversal(treeNode* root){
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
    int ele;
    while(ele!=-1){
        cin>>ele;
        if(ele==-1){
            break;
        }
        root = insert(root,ele);
    }
    level_order_traversal(root);
    return 0;
}