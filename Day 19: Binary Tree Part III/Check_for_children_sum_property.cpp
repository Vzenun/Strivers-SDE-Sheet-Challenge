#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int ans(BinaryTreeNode < int > * root){
    if(root->right==nullptr && root->left==nullptr){
        root->data=1000000;
        return root->data;
    }
    else if(root->right==nullptr){
        int a1=ans(root->left);
        root->data=a1;
        return root->data;
    }
    else if(root->left==nullptr){
        int a1=ans(root->right);
        root->data=a1;
        return root->data;
    }
    else{
        int a1=ans(root->left);
        int a2=ans(root->right);
        root->data=a1+a2;
        return root->data;
    }
}
void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    if(root==nullptr){
        return;
    }
    ans(root);
    return;
}  