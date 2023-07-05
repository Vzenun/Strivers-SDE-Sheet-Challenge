/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/

bool check(BinaryTreeNode<int>* root1,BinaryTreeNode<int>* root2){
    if(root1==nullptr && root2==nullptr){
        return true;
    }
    else if(root1==nullptr || root2==nullptr){
        return false;
    }
    else{
        bool a1=check(root1->left,root2->right);
        bool a2=check(root1->right,root2->left);
        if(a1==a2 && a1==true && root1->data==root2->data){
            return true;
        }
        return false;
    }
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here.  
    if(root==nullptr){
        return true;
    }
    return  check(root->left,root->right);
}