#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    stack<BinaryTreeNode<int> *> st1;
    stack<BinaryTreeNode<int> *> st2;
    int i=0;
    vector<int> ans;
    if(root==nullptr){
        return ans;
    }
    st1.push(root);
    while(!(st1.empty() && st2.empty())){
        if(i%2==0){
            int n=st1.size();
            for(int i=0;i<n;i++){
                BinaryTreeNode<int> * k=st1.top();
                st1.pop();
                ans.emplace_back(k->data);
                if(k->left!=nullptr){
                    st2.push(k->left);
                }
                if(k->right!=nullptr){
                    st2.push(k->right);
                }
            }
        }
        else{
            int n=st2.size();
            for(int i=0;i<n;i++){
                BinaryTreeNode<int> * k=st2.top();
                st2.pop();
                ans.emplace_back(k->data);
                if(k->right!=nullptr){
                    st1.push(k->right);
                }
                if(k->left!=nullptr){
                    st1.push(k->left);
                }
            }
        }
        i++;
    }
    return ans;
}
