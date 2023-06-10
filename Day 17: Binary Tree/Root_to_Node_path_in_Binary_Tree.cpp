#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
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
*/

vector<int> ans;
void trav(TreeNode<int> *root,int x,vector<int> k){
    if(root==nullptr){
        return;
    }
    else{
		if(root->data==x){
			k.emplace_back(x);
			ans=k;
			return;
		}
    	k.emplace_back(root->data);
        trav(root->left,x,k);
        trav(root->right,x,k);
    }
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int> s;
	trav(root,x,s);
    vector<int> k=ans;
    ans.clear();
    return k;
}
