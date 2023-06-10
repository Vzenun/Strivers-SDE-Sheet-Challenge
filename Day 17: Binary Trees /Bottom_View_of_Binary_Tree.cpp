#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    map<int,int> mpt;
    vector<int> ans;
    if(root==nullptr){
        return ans;
    }
    queue<pair<BinaryTreeNode<int> *,int>> q;
    q.emplace(root,0);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            BinaryTreeNode<int> * k=q.front().first;
            int num=q.front().second;
            q.pop();
            mpt[num]=k->data;
            if(k->left!=nullptr){
                q.emplace(k->left,num-1);
            }
            if(k->right!=nullptr){
                q.emplace(k->right,num+1);
            }
        }
    }
    map<int,int> :: iterator it=mpt.begin();
    while(it!=mpt.end()){
        ans.emplace_back(it->second);
        it++;
    }
    return ans;
}
