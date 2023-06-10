#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    map<int,vector<int>> mpt;
    vector<int> ans;
    if(root==nullptr){
        return ans;
    }
    queue<pair<TreeNode<int> *,int>> q;
    q.emplace(root,0);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            TreeNode<int> * k=q.front().first;
            int num=q.front().second;
            q.pop();
            mpt[num].emplace_back(k->data);
            if(k->left!=nullptr){
                q.emplace(k->left,num-1);
            }
            if(k->right!=nullptr){
                q.emplace(k->right,num+1);
            }
        }
    }
    map<int,vector<int>> :: iterator it=mpt.begin();
    while(it!=mpt.end()){
        for(int i=0;i<it->second.size();i++){
            ans.emplace_back(it->second[i]);
        }
        it++;
    }
    return ans;
}