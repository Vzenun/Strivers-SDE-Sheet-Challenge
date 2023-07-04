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
vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> inorder;
    if(root==nullptr){
        return inorder;
    }
    TreeNode* curr=root;
    while(curr!=nullptr){
        if(curr->left==nullptr){
            inorder.emplace_back(curr->data);
            curr=curr->right;
        }
        else{
            TreeNode * k3=curr->left;
            while(k3->right!=nullptr && k3->right!=curr){
                k3=k3->right;
            }
            if(k3->right==nullptr){
                k3->right=curr;
                curr=curr->left;
            }
            else{
                inorder.emplace_back(curr->data);
                k3->right=nullptr;
                curr=curr->right;
            }
        }
    }
    return inorder;
}