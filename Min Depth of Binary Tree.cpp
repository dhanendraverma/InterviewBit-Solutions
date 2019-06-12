
int Solution::minDepth(TreeNode* A) {
    if(!A)
        return 0;
    if(A->left==NULL && A->right==NULL)
        return 1;
    if(!A->left)
        return minDepth(A->right)+1;
    else if(!A->right)
        return minDepth(A->left)+1;
    return 1+min(minDepth(A->right),minDepth(A->left));
}
