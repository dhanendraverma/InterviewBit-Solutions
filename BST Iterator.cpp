
stack<TreeNode*> st;

BSTIterator::BSTIterator(TreeNode *root) {
    
    while(root!=NULL) //only push left most branch element at last stack will contain only smallest element and other elements in its path
    {
        st.push(root);
        root = root->left;
    }

}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return !(st.empty()); //if it's not empty return true beacuse it has next element wherease if it's empty that mean it has no next
                          //element hence return false

}

/** @return the next smallest number */
int BSTIterator::next(){
    TreeNode* temp = st.top(); 
    st.pop();
    int ans = temp->val;
    temp = temp->right; //since we did not explore right side element we should explore as these are next smaller elements then whixh are
                        //already in stack
    while(temp!=NULL)
    {
        st.push(temp);
        temp = temp->left;
    }
    return ans;

}
