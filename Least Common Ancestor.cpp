/*The only extra work need to do in order to solve this problme in addition to finding LCA we need to check if both values exists in the
tree or not. Beacuse traditional mehtod to find lca return a node where where either of values matches first incase if anyone of them 
missing from tree that method will a node whose value is equal to the non missing values. In order to solve this problem just check if
both values really exists in the tree or not I have implemented a find menthod which will do this work when both of the values exists 
then only find lca*?

bool find(TreeNode* root, int val)
{
    if (!root)
        return false;
    if (root->val == val)
        return true;
    if (root->val==val || find(root->left, val) || find(root->right, val))
        return true;
    return false;
}

TreeNode* LCA(TreeNode* root, int v1, int v2)
{
    if (!root || root->val == v1 || root->val == v2)
        return root;
    
    TreeNode* left = LCA(root->left, v1, v2);
    TreeNode* right = LCA(root->right, v1, v2);
    
    if (left && right)
        return root;
    return left ? left : right;
}

int Solution::lca(TreeNode* A, int B, int C) {
    if (find(A,B) && find(A,C)){
        auto ancestor = LCA(A, B, C);
        if (ancestor)
            return ancestor->val;
    }
    return -1;
}
