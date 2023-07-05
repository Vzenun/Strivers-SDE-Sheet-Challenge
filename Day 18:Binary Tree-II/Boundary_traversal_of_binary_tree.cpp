#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> ans;
    if(root==nullptr){
        return ans;
    }
    ans.push_back(root->data);
    TreeNode<int> *k=root->left;
    root->data=-1;
    while(k!=nullptr){
        if(k->left!=nullptr){
            ans.push_back(k->data);
            k->data=-1;
            k=k->left;
        }
        else{
            ans.push_back(k->data);
            k->data=-1;
            k=k->right;
        }
    }
    stack<TreeNode<int> *> q1;
    q1.push(root);
    while(!q1.empty()){
        int n=q1.size();
        for(int i=0;i<n;i++){
            TreeNode<int> * k=q1.top();
            q1.pop();
            if(k->data>0 && k->left==nullptr && k->right==nullptr){
                ans.emplace_back(k->data);
                k->data=-1;
            }
            if(k->right!=nullptr){
                q1.push(k->right);
            }
            if(k->left!=nullptr){
                q1.push(k->left);
            }
        }
    }
    vector<int> a1;
    k=root->right;
    while(k!=nullptr){
        if(k->right!=nullptr){
            if(k->data!=-1){
                a1.push_back(k->data);
            }
            k->data=-1;
            k=k->right;
        }
        else{
            if(k->data!=-1){
                a1.push_back(k->data);
            }
            k->data=-1;
            k=k->left;
        }
    }
    while(a1.size()!=0){
        ans.push_back(a1[a1.size()-1]);
        a1.pop_back();
    }
    return ans;
}