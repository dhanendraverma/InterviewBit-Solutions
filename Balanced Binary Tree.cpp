
int checkBalance(TreeNode* root,int *h){
    
    int lh=0,rh=0;
    
    if(!root)
    {
        *h = 0;
        return 1;
    }
    
    int l = checkBalance(root->left,&lh);
    int r = checkBalance(root->right,&rh);
    
    *h = max(lh,rh)+1;
    
    if(abs(lh-rh)>1)
        return 0;
    if(l&&r) return 1;
    return 0;
    
}
 
 
int Solution::isBalanced(TreeNode* A) {
    int h = 0;
    return checkBalance(A,&h);
}
