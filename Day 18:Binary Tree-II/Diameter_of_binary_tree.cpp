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
int diameter=0;

int height(TreeNode<int> *root){
    if(root==nullptr){
        return 0;
    }
    else{
        int lh=1+height(root->left);
        int rh=1+height(root->right);
        diameter=max(diameter,1+lh+rh-2);
        return max(lh,rh);
    }
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    diameter=0;
    height(root);
    return diameter-1;
}
