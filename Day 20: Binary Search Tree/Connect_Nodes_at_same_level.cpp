#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode< int > *root) {
    // Write your code here.
    queue<BinaryTreeNode< int > *> q;
    if(root==nullptr){
        return;
    }
    q.push(root);
    BinaryTreeNode< int > * k;
    int num=0;
    BinaryTreeNode< int > * prev;
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            if(num==0){
                k=q.front();
                q.pop();
                k->next=nullptr;
                if(k->left!=nullptr){
                    q.push(k->left);
                }
                if(k->right!=nullptr){
                    q.push(k->right);
                }
            }
            else{
                if(i==0){
                    k=q.front();
                    q.pop();
                    prev=k;
                    if(k->left!=nullptr){
                        q.push(k->left);
                    }
                    if(k->right!=nullptr){
                        q.push(k->right);
                    }
                }
                else{
                    k=q.front();
                    q.pop();
                    prev->next=k;
                    prev=prev->next;
                    if(k->left!=nullptr){
                        q.push(k->left);
                    }
                    if(k->right!=nullptr){
                        q.push(k->right);
                    }
                }
            }
        }
        num++;
    }
    return;
}