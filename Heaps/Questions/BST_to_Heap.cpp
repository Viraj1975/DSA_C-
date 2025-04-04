#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int value;
        Node* left;
        Node* right;

        Node(){
            left = NULL;
            right = NULL;
        }
};

void inorder_traversal(Node* root,vector<int>v){
    if(root==NULL) return;
    inorder_traversal(root->left,v);
    v.push_back(root->value);
    inorder_traversal(root->right,v);
}

void Pre_order_traversal(Node* root,vector<int>v){
    if(root==NULL) return;
    root->value = v[0];
    v.erase(v.begin());
    Pre_order_traversal(root->left,v);
    Pre_order_traversal(root->right,v);
}

void BST_to_Heap(Node* root){
    vector<int>v;
    inorder_traversal(root,v);
    Pre_order_traversal(root,v);
}

int main(){
    return 0;
}

