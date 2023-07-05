#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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


int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	//    Write your code here
    if(root==nullptr){
        return -1;
    }
    int l1=lowestCommonAncestor(root->left,x,y);
    int l2=lowestCommonAncestor(root->right,x,y);
    if(l1==-1 && l2==-1){
        if (root->data == x || root->data == y) {
            return -2;
        }
        else{
            return -1;
        }
    }
    else if(l1==-2 && l2==-2){
        return root->data;
    }
    else if(l1==-2 || l2==-2){
        if (root->data == x || root->data == y) {
            return root->data;
        }
        else{
            return -2;
        }
    }
    else{
        return max(l1,l2);
    }
}