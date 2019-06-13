/*As inorder traversal of binary search tree gives the node values in sorted order just keep doing inroder traversal untill you have
visited total of k elements when we visit kth element set this to ans return*/


void inorder(TreeNode* root, int B, int &count, int&ans)
{
    if(!root)
        return;
    inorder(root->left, B, count,ans);
    count++;
    if(count==B){
        ans =root->val;
        return;
    }
        
    inorder(root->right, B, count,ans);
}



int Solution::kthsmallest(TreeNode* A, int B) {
    int count=0,ans;
    inorder(A,B,count,ans);
    return ans;
}
