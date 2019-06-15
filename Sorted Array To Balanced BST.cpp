

TreeNode* generateBST(const vector<int> &A, int low, int high){
    if(low > high)
        return NULL;
    
    int mid = low + (high - low)/2; //to prevent int overflow
    
    TreeNode* root = new TreeNode(A[mid]); //always create a node with the middle element
                                        //this makes sure that tree is balanced
    
    root->left = generateBST(A, low, mid-1); //now again recur for the left side and do the same
    
    root->right = generateBST(A, mid+1, high);
    
    return root;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    return generateBST(A, 0, A.size()-1);

}
