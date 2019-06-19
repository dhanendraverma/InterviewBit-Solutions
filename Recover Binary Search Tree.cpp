/*As we know the inorder traversal of the BST give the values in sorted order hence traverse the tree in inorder fashion. While doing 
so keep checking if the current value and last seen value are not in increasing order if such case in encountered for the first time 
remember the value of prev in first and when we again encounter such case we will already be holding the value in first so update 
the value in last in case two values are adjancent so we will never encounter the case for the second time. Now we have our two values
in variable first and second. */




vector<int> Solution::recoverTree(TreeNode* A) {
    vector<int> ans;
    stack<TreeNode*> st;
    bool done = false;
    TreeNode *curr=A,*prev=NULL,*first=NULL,*last=NULL;
    
    while(!st.empty() || curr!=NULL){
        while(curr!=NULL){
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        if(prev!=NULL){
            if(prev->val>curr->val){
                if(first==NULL){
                    first = prev;
                    
                }
                last = curr;
                
            }
            
        }
        prev = curr;
        curr = curr->right;
        
    }
    ans.push_back(first->val);
    ans.push_back(last->val);
    sort(ans.begin(),ans.end());
    return ans;
}
