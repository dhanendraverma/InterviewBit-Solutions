
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    vector<vector<int> > ans;
    if(!A)
        return ans;
    
    queue<pair <TreeNode*, int> > q;
    q.push({A, 0});
    map<int, vector<int> > mp;
    
    while(!q.empty()){
        pair<TreeNode*, int> temp = q.front();
        q.pop();
        
        if(temp.first->left)
            q.push({temp.first->left, temp.second-1});
        
        if(temp.first->right)
            q.push({temp.first->right, temp.second+1});
        mp[temp.second].push_back(temp.first->val);
    }

    for(auto it : mp)
        ans.push_back(it.second);
    
    return ans;
}
