#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* x, TreeNode<int>* y)
{
	// Write your code here
    if(root==nullptr){
        return nullptr;
    }
    if(root==x || root==y){
        return root;
    }
    else{
        if(root->data<x->data && root->data<y->data){
            return  LCAinaBST(root->right,x,y);
        }
        else if(root->data>x->data && root->data>y->data){
            return  LCAinaBST(root->left,x,y);
        }
        else{
            return root;
        }
    }
}
