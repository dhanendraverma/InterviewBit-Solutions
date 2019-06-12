
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    if(!A && !B)
        return 1;
    else if(!A || !B)
        return 0;
    else if((A->val==B->val) && isSameTree(A->left,B->left) && isSameTree(A->left,B->left))
        return 1;
    else
        return 0;
}
