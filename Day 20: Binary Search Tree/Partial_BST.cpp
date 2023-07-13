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
bool check(BinaryTreeNode<int> *root) {
    // Write your code here.
    if(root->left==nullptr && root->right==nullptr){
        return true;
    }
    else{
        if(root->left==nullptr){
            bool a1=check(root->right);
            if(a1 && root->data<=root->right->data){
                return true;
            }
            else{
                return false;
            }
        }
        else if(root->right==nullptr){
            bool a1=check(root->left);
            if(a1 && root->data>=root->left->data){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            bool a1=check(root->right);
            bool a2=check(root->left);
            if(a1 && a2 && root->data<=root->right->data && root->data>=root->left->data){
                return true;
            }
            else{
                return false;
            }
        }
    }
}
bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==nullptr){
        return true;
    }
    return check(root);
}