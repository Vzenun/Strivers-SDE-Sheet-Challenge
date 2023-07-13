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
TreeNode<int>* construct(vector<int> &arr,int i,int j){
    if(i==j){
        return new TreeNode<int>(arr[i]);
    }
    else if(i>j){
        return nullptr;
    }
    else{
        int m=(i+j)/2;
        TreeNode<int>* root=new TreeNode<int>(arr[m]);
        root->left=construct(arr,i,m-1);
        root->right=construct(arr,m+1,j);
        return root;
    }
}
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    return construct(arr,0,n-1);
}