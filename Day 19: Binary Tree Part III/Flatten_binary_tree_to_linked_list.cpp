#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

    template <typename T>
    class TreeNode {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    TreeNode<int> *root1=root;
    while(root1!=nullptr){
        if(root1->left==nullptr){
            root1=root1->right;
        }
        else{
            TreeNode<int> *k=root1->left;
            while(k->right!=nullptr){
                k=k->right;
            }
            k->right=root1->right;
            k=root1->right;
            root1->right=root1->left;
            root1->left=nullptr;
            root1=root1->right;
        }
    }
    return root;
}