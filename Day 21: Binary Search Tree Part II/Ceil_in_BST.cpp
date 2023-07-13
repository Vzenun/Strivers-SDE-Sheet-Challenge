#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
                delete left;
            }
            if (right) {
                delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *root, int X){
    // Write your code here.
    if(root==nullptr){
        return -1;
    }
    else{
        if(root->data==X){
            return X;
        }
        else if(root->data<X){
            int a1=findCeil(root->right,X);
            if(root->data>=X && (a1==-1 || root->data<a1)){
                return root->data;
            }
            else{
                return a1;
            }
        }
        else{
            int a1=findCeil(root->left,X);
            if(root->data>=X && (a1==-1 || root->data<a1)){
                return root->data;
            }
            else{
                return a1;
            }
        }
    }
}