
int Solution::hasPathSum(TreeNode* A, int B) {
    if(!A)
    {
        if(B==0)
            return 1;
        return 0;
    }
    
    if((B-A->val)==0 && A->left==NULL && A->right==NULL)
        return 1;
    if(A->left && hasPathSum(A->left,B-A->val))
        return 1;
    if(A->right && hasPathSum(A->right,B-A->val))
        return 1;
    return 0;
    
}
