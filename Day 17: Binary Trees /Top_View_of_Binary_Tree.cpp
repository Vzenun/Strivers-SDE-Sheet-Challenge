#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

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

vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    map<int,set<int>> mpt;
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
            if(mpt[num].size()==0){
                mpt[num].insert(k->val);
            }
            if(k->left!=nullptr){
                q.emplace(k->left,num-1);
            }
            if(k->right!=nullptr){
                q.emplace(k->right,num+1);
            }
        }
    }
    map<int,set<int>> :: iterator it=mpt.begin();
    while(it!=mpt.end()){
        ans.emplace_back(*(it->second.begin()));
        it++;
    }
    return ans;
}