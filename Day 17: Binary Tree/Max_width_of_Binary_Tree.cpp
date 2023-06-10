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

int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    int ans=-1;
    if(root==nullptr){
        return 0;
    }
    queue<TreeNode<int> *> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        ans=max(n,ans);
        for(int i=0;i<n;i++){
            TreeNode<int> * k=q.front();
            q.pop();
            if(k->left!=nullptr){
                q.push(k->left);
            }
            if(k->right!=nullptr){
                q.push(k->right);
            }
        }
    }
    return ans;
}