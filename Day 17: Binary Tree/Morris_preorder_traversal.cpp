#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> preorder;
    if(root==nullptr){
        return preorder;
    }
    TreeNode* curr=root;
    while(curr!=nullptr){
        if(curr->left==nullptr){
            preorder.emplace_back(curr->data);
            curr=curr->right;
        }
        else{
            preorder.emplace_back(curr->data);
            TreeNode * k3=curr->left;
            while(k3->right!=nullptr){
                k3=k3->right;
            }
            k3->right=curr->right;
            curr=curr->left;
        }
    }
    return preorder;
}