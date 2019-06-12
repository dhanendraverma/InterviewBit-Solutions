//decrease the sum while doing DFS when we hit a leaf and sum is zero that means current path sum leads to the sum required
int Solution::hasPathSum(TreeNode* A, int B) {
    if(!A) //if current root is null and sum to be checked is 0 so we can return 1
    {
        if(B==0)
            return 1;
        return 0;
    }
    
    if((B-A->val)==0 && A->left==NULL && A->right==NULL) //if root is leaf ans sum is 0
        return 1;
    if(A->left && hasPathSum(A->left,B-A->val)) //if left side path has sum path
        return 1;
    if(A->right && hasPathSum(A->right,B-A->val)) //else if right side tree has path sum
        return 1;
    return 0; //neither node nor its right nor its left has path sum
    
}
