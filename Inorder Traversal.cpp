
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> ans;
    stack<TreeNode*> s;

    TreeNode* curr = A;

    while(true)
    {
        if(curr != NULL) //go to the left most node till you can
        {
            s.push(curr); //push all the left side node as in inorder everything on left
                         //is visited before node and everything on right.
            curr = curr->left;
        }

        else
        {
            if(s.empty()) //if stack is empty emtpy then there are no more nodes
                break;
            curr = s.top(); //when curr is null there are no more left child print
                            //currrent node value are recur for right child
            s.pop();
            ans.push_back(curr->val);
            curr = curr->right;

        }

    }


    return ans;

}
