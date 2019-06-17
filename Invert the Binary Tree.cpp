
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 void invert(TreeNode* root)
 {
     if(!root) //if node is null simply return
        return;
     else
     {
        invert(root->left); //invert left and right basically invert lower levels then come in upside
        invert(root->right);
        TreeNode* temp = root->right; //at every node just swap its left and right child 
                                    //in this manner tree will get swapped at all the level from bottom to top
        root->right = root->left;
        root->left = temp;
     }
        
 }
 
 
TreeNode* Solution::invertTree(TreeNode* A) {
    invert(A); //helper function
    return A;
}
