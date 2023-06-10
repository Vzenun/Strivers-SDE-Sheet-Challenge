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

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int> ans;
    if(root==nullptr){
        return ans;
    }
    queue<TreeNode<int> *> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            TreeNode<int> * k=q.front();
            q.pop();
            if(i==0){
                ans.emplace_back(k->data);
            }
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