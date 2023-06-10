#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> preorder;
    vector<int> postorder;
    vector<int> inorder;
    if(root==nullptr){
        ans.push_back(inorder);
        ans.push_back(preorder);
        ans.push_back(postorder);
        return ans;
    }
    stack<pair<BinaryTreeNode<int> *,int>> st;
    st.emplace(root,-1);
    BinaryTreeNode<int> * lh;
    BinaryTreeNode<int> * rh;
    while(!st.empty()){
        BinaryTreeNode<int> *k=st.top().first;
        int num=st.top().second;
        st.pop();
        if(k->left==nullptr && k->right==nullptr){
            if(num==-1){
                preorder.emplace_back(k->data);
                inorder.emplace_back(k->data);
                postorder.emplace_back(k->data);
            }
            else if(num==1){
                inorder.emplace_back(k->data);
            }
            else if(num==2){
                preorder.emplace_back(k->data);
            }
            else if(num==3){
                postorder.emplace_back(k->data);
            }
        }
        else{
            lh=k->left;
            rh=k->right;
            k->left=nullptr;
            k->right=nullptr;
            st.emplace(k,3);
            if(rh!=nullptr){
                st.emplace(rh,-1);
            }
            st.emplace(k,1);
            if(lh!=nullptr){
                st.emplace(lh,-1);
            }
            st.emplace(k,2);
        }
    }
    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);
    return ans;
}