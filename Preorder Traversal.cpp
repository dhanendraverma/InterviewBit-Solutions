
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> ans;
    TreeNode* curr = A;
    stack<TreeNode*> st;
    st.push(curr); //get root into stack
    while(!st.empty())
    {
        curr = st.top(); //get lastmost element
        st.pop(); 
        ans.push_back(curr->val); //get its value
        if(curr->right) //if it's right push right
            st.push(curr->right);
        if(curr->left) //if it's left push left since stack LIFO so we push right first and then left
            st.push(curr->left);
        
    }
    return ans;
}
