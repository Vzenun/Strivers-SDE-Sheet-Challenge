#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int answer=0;
long long int ans(TreeNode<int> *root){
    if(root==nullptr){
        return -1;
    }
    else{
        int a1=ans(root->left);
        int a2=ans(root->right);
        if(a1!=-1 && a2!=-1){
            answer=max(a1+a2+root->val,answer);
        }
        if(a1>=a2){
            if(a1!=-1){
                return a1+root->val;
            }
            else{
                return root->val;
            }
        }
        else{
            if(a2!=-1){
                return a2+root->val;
            }
            else{
                return root->val;
            }
        }
    }
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here
    answer=-1;
    ans(root);
    return answer;

}