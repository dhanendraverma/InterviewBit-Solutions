
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
     vector<vector<int>> ans;
      if (!A) 
        return ans; 
  
 
    stack<TreeNode*> currentlevel; 
    stack<TreeNode*> nextlevel; 
        currentlevel.push(A); 
        vector<int> temp1;
  
    bool lefttoright = true; 
    while (!currentlevel.empty()) { 
  
  TreeNode* temp = currentlevel.top(); 
        currentlevel.pop(); 
  
           if (temp) { 
  
             
            temp1.push_back(temp->val); 
  
            if (lefttoright) { 
                if (temp->left) 
                    nextlevel.push(temp->left); 
                if (temp->right) 
                    nextlevel.push(temp->right); 
            } 
            else { 
                if (temp->right) 
                    nextlevel.push(temp->right); 
                if (temp->left) 
                    nextlevel.push(temp->left); 
            } 
        } 
  
        if (currentlevel.empty()) { 
            lefttoright = !lefttoright; 
            swap(currentlevel, nextlevel); 
            ans.push_back(temp1);
            temp1.clear();
        } 
    }
        return ans;
    }
  
