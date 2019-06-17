
 
 void flattree(TreeNode* root){
    if(root==NULL || root->right==NULL && root->left==NULL) //base if root is null of it's a leaf node
        return;
    if(root->left){  //wheneve there is left tree make is as a right tree and set the left child as null however before doin this 
                  //store the right in temp and connect the right tree at the last of the subtree which was connected from left to tree
        flattree(root->left);
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = NULL;
        TreeNode* lastright = root->right;
        while(lastright->right)
            lastright=lastright->right;
        lastright->right = temp;
    }
    flattree(root->right);
 }
 
 
TreeNode* Solution::flatten(TreeNode* A) {
   
    flattree(A);
    return A;
}
