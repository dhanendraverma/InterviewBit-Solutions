/*We know that leftmost element in preorder sequence is the root of the tree.We can easliy get the root of the tree by using preorder. 
As we also know that in inorder traversal first root then left, atlast right is visited, so once you have root you can get the elements in
left of the root as well in the in the right by using inorder sequence. Now follow the same approach for the left side elements and right
side elements.*/

 
int findIndex(vector<int> &inorder, int start, int end, int val)
{
    for (int i=start; i<=end; i++)
        if (inorder[i]==val)
            return i;
}

TreeNode* BuildTree(vector<int> &preorder, vector<int> &inorder, int start, int end, int& pindex)
{
    if (start>end) //if we are done with the current part
        return NULL;
    
    TreeNode* node = new TreeNode(preorder[pindex++]); 
    
    if (start==end) //when there are no chlildren of the current node
        return node;
    
    int index = findIndex(inorder, start, end, node->val); ///get index in preorder sequence
    node->left = BuildTree(preorder, inorder, start, index-1, pindex); //create for left side and right side
    node->right = BuildTree(preorder, inorder, index+1, end, pindex);
    
    return node;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {

    int preindex = 0; 
    return BuildTree(A, B, 0, A.size()-1, preindex);
}
