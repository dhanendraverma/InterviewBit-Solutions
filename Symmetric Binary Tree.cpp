
int isMirror(TreeNode* root1, TreeNode* root2){
    if(!root1 && !root2) //if both node are null then they are symmetric
        return 1;
    if(root1 && root2 && root1->val==root2->val) //if both of them are not null and
                                                //their values are equal
    {
        if(isMirror(root1->left, root2->right) && isMirror(root1->right,root2->left))
            return 1; //check for symmetricity in subtrees in opposite sides of 2 roots
        else 
            return 0;
        
    }
        
    else //all other cases can not make symmetric tree
        return 0;
}
 
 
int Solution::isSymmetric(TreeNode* A) {
    return isMirror(A,A);
}
