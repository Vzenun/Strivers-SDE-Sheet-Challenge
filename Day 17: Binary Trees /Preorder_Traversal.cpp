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
vector<int> ans;
void trav(TreeNode *root){
    if(root==nullptr){
        return;
    }
    else{
        ans.emplace_back(root->data);
        trav(root->left);
        trav(root->right);
    }
}
vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    trav(root);
    vector<int> k=ans;
    ans.clear();
    return k;
}