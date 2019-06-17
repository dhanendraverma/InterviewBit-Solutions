
int findIndex(vector<int>& inorder, int start, int end, int val)
{
    for (int i = start; i<=end; i++)
        if (inorder[i] == val)
            return i;
}

TreeNode* makeTree(vector<int> &inorder, vector<int> &postorder, int start, int end, int& pindex)
{
    if (start>end)
        return NULL;
    TreeNode* node = new TreeNode(postorder[pindex--]);
    if (start==end)
        return node;
    int index = findIndex(inorder, start, end, node->val);
    
    node->right = makeTree(inorder, postorder, index+1, end, pindex); //always creat right before left 
    node->left = makeTree(inorder, postorder, start, index-1, pindex);
    
    return node;
}

TreeNode* Solution::buildTree(vector<int> &inorder, vector<int> &postorder) {
    int postindex = postorder.size()-1;
    return makeTree(inorder, postorder, 0, inorder.size()-1, postindex);
}
