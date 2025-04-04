#include<bits/stdc++.h>
using namespace std;

class treeNode{
    public:
        int value;
        treeNode* left;
        treeNode* right;
        int height;
        treeNode(int value){
            this->value = value;
            left = NULL;
            right = NULL;
            height = 1;
        }
};

int height(treeNode* N){
    if(N==NULL) return 0;
    return N->height;
}

int max(int a,int b){
    return (a>b)?a:b;
}

int get_Balance(treeNode* N){
    if(N==NULL) return 0;
    return height(N->left)-height(N->right);
}

treeNode* left_rotate(treeNode* y){
    treeNode* x = y->right;
    treeNode* t2 = x->left;

    x->left = y;
    y->right = t2;

    x->height = max(height(x->left),height(x->right))+1; 
    y->height = max(height(y->left),height(y->right))+1;

    return x;
}

treeNode* right_rotate(treeNode* y){
    treeNode* x = y->left;
    treeNode* t2 = x->right;

    x->right = y;
    y->left = t2;

    x->height = max(height(x->left),height(x->right))+1; 
    y->height = max(height(y->left),height(y->right))+1;

    return x;
}

treeNode* insert(treeNode* root,int key){
    if(root==NULL){
        return new treeNode(key);
    }
    if(root->value>key){
        root->left = insert(root->left,key);
    }
    else if(root->value<key){
        root->right = insert(root->right,key);
    }
    else{
        return root;
    }

    root->height = 1 + max(height(root->left),height(root->right));

    int balance = get_Balance(root);

    if(balance>1 && root->left->value>key){
        return right_rotate(root);
    } 
    if(balance>1 && root->left->value<key){
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    if(balance<-1 && root->right->value<key){
        return left_rotate(root);
    }
    if(balance<-1 && root->right->value>key){
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

void level_order_traversal(treeNode* root){
    if(root==NULL) return;
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

void pre_order_traversal(treeNode* root){
    if(root==NULL) return;
    cout<<root->value<<" ";
    pre_order_traversal(root->left);
    pre_order_traversal(root->right);
}

int main(){
    treeNode* root = NULL;
    // int ele;
    // while(ele!=-1){
    //     cin>>ele;
    //     if(ele==-1){
    //         break;
    //     }
    //     root = insert(root,ele);
    // }

    root = insert(root, 10);  
    root = insert(root, 20);  
    root = insert(root, 30);  
    root = insert(root, 40);  
    root = insert(root, 50);  
    root = insert(root, 25); 

    // level_order_traversal(root);
    pre_order_traversal(root);
    return 0;
}