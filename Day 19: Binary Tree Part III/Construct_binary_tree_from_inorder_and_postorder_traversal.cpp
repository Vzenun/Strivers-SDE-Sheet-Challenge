#include<bits/stdc++.h>
/************************************************************
    
    Following is the TreeNode class structure
    
    class TreeNode<T>
    { 
    public:
            T data; 
            TreeNode<T> *left;
            TreeNode<T> *right;
    
            TreeNode(T data) 
            { 
                this -> data = data; 
                left = NULL; 
                right = NULL; 
            }
    };
    
    
 ************************************************************/
int i1=0;
TreeNode<int> * construct(vector<int> &postorder,int i,int j,map<int,int> &mpt,TreeNode<int> * &root){
    if(i1<0 || i>j){
        return nullptr;
    }
    if (i == j) {
        root = new TreeNode<int>(postorder[i1]);
        i1--;
        return root;
    }
    root = new TreeNode<int>(postorder[i1]);
    int a1=mpt[postorder[i1]];
    i1--;
    root->right=construct(postorder,a1+1,j,mpt,root->right);
    root->left=construct(postorder,i,a1-1,mpt,root->left);
    return root;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	// Write your code here.
    i1=postOrder.size()-1;
    map<int,int> mpt;
    for(int i=0;i<inOrder.size();i++){
        mpt[inOrder[i]]=i;
    }
    TreeNode<int> * root=nullptr;
    return construct(postOrder,0,postOrder.size()-1,mpt,root);
}
