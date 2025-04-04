#include<iostream>
#include<queue>
using namespace std;

class treeNode{
    public:
        int value;
        treeNode* left = NULL;
        treeNode* right = NULL;
        treeNode(int value){
            this->value = value;
            left = NULL;
            right = NULL;
        }
};

treeNode* insert(treeNode* root,int value){
    treeNode* newNode = new treeNode(value);;
    if(root==NULL){
        root = newNode;
        return root;
    }
    queue<treeNode*>q;
    q.push(root);
    treeNode* temp;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp->left){
            q.push(temp->left);
        }
        else{
            temp->left = newNode;
            break;
        }
        if(temp->right){
            q.push(temp->right);
        }
        else{
            temp->right = newNode;
            break;
        }
    }
    return root;
}

void Morris_Traversal(treeNode* root){
    treeNode* curr = root;
    while(curr!=NULL){
        if(curr->left==NULL){
            cout<<curr->value<<" ";
            curr=curr->right;
        }
        else{
            treeNode* pred = curr->left;
            while(pred->right!=NULL && pred->right!=curr){
                pred=pred->right;
            }
            
            if(pred->right==NULL){
                pred->right=curr;
                curr=curr->left;
            }
            else{
                pred->right=NULL;
                cout<<curr->value<<" ";
                curr=curr->right;
            }
        }
    }
}

int main(){
    treeNode* root = NULL;
    for(int i=1;i<=10;i++){
        root = insert(root,i);
    }
    Morris_Traversal(root);
    return 0;
}