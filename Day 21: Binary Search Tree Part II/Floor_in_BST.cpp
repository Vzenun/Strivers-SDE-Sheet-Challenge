#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    if(root==nullptr){
        return -1;
    }
    else{
        if(root->val==X){
            return X;
        }
        else if(root->val<X){
            int a1=floorInBST(root->right,X);
            if(root->val<=X && root->val>a1){
                return root->val;
            }
            else{
                return a1;
            }
        }
        else{
            int a1=floorInBST(root->left,X);
            if(root->val<=X && root->val>a1){
                return root->val;
            }
            else{
                return a1;
            }
        }
    }
}