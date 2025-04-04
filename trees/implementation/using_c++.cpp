#include<bits/stdc++.h>
using namespace std;

class treeNode{
    public:
        int value;
        treeNode* left;
        treeNode* right;
        treeNode(int value){
            this->value=value;
            left=NULL;
            right=NULL;
        }
};

treeNode* insert(treeNode* root,int ele){
    if(root==NULL){
        root = new treeNode(ele);
        return root;
    }
    queue<treeNode*>q;
    q.push(root);
    while(!q.empty()){
        treeNode* temp = q.front();
        q.pop();
        if(temp->left==NULL){
            temp->left = new treeNode(ele);
            break;
        }else{
            q.push(temp->left);
        }
        if(temp->right==NULL){
            temp->right = new treeNode(ele);
            break;
        }else{
            q.push(temp->right);
        }
    }
    return root;
}

void delete_deepest(treeNode* root,treeNode* d_Node){
    queue<treeNode*>q;
    q.push(root);
    treeNode* temp;

    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp==d_Node){
            temp=NULL;
            delete d_Node;
            return;
        }
        if(temp->left==d_Node){
            temp->left=NULL;
            delete(d_Node);
            return;
        }else{
            q.push(temp->left);
        }
        if(temp->right==d_Node){
            temp->right=NULL;
            delete(d_Node);
            return;
        }else{
            q.push(temp->right);
        }
    }
}

treeNode* deletion(treeNode* root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        if(root->value==key){
            return NULL;
        }
        else{
            return root;
        }
    }

    queue<treeNode*>q;
    treeNode* temp;
    treeNode* key_node = NULL;
    q.push(root);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp->value==key){
            key_node=temp;
        }
        if(temp->left!=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
    }
    if(key_node!=NULL){
        int x = temp->value;
        key_node->value=x;
        delete_deepest(root,temp);
    }
    return root;
}

void level_order_traversal(treeNode* root){
    if(root==NULL){
        return;
    }
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

void in_order_Traversal(treeNode* root){
    if(!root) return;
    in_order_Traversal(root->left);
    cout<<root->value<<" ";
    in_order_Traversal(root->right);
}

void Pre_order_Traversal(treeNode* root){
    if(!root) return;
    cout<<root->value<<" ";
    Pre_order_Traversal(root->left);
    Pre_order_Traversal(root->right);
}

void Post_order_Traversal(treeNode* root){
    if(!root) return;
    Post_order_Traversal(root->left);
    Post_order_Traversal(root->right);
    cout<<root->value<<" ";
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
    level_order_traversal(root);cout<<"\n";
    in_order_Traversal(root);cout<<"\n";
    Pre_order_Traversal(root);cout<<"\n";
    Post_order_Traversal(root);cout<<"\n";
    return 0;
}