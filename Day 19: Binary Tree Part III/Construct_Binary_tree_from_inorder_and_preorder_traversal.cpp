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
int i1=0;
TreeNode<int> * construct(vector<int> &preorder,int i,int j,map<int,int> &mpt,TreeNode<int> * &root){
    if(i1>=preorder.size() || i>j){
        return nullptr;
    }
    if (i == j) {
        root = new TreeNode<int>(preorder[i1]);
        i1++;
        return root;
    }
    root = new TreeNode<int>(preorder[i1]);
    int a1=mpt[preorder[i1]];
    i1++;
    root->left=construct(preorder,i,a1-1,mpt,root->left);
    root->right=construct(preorder,a1+1,j,mpt,root->right);
    return root;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
    i1=0;
    map<int,int> mpt;
    for(int i=0;i<inorder.size();i++){
        mpt[inorder[i]]=i;
    }
    TreeNode<int> * root=nullptr;
    return construct(preorder,0,preorder.size()-1,mpt,root);
}