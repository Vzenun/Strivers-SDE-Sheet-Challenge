#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int height(BinaryTreeNode<int>* root){
    if(root==nullptr){
        return 0;
    }
    else{
        int lh=1+height(root->left);
        int rh=1+height(root->right);
        if(lh==0 || rh==0){
            return -1;
        }
        if(abs(lh-rh)<=1){
            return max(lh,rh);
        }
        else{
            return -1;
        }
    }
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    if(height(root)==-1){
        return false;
    }
    else{
        return true;
    }
}