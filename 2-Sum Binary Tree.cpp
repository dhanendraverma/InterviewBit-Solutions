/*Traverse the tree in any fashion ie inorder,preorder,postorder and keep inserting element in a container every at every stage check if
there exist an element in the stored elements which on adding with the current element give the desired sum. This can be done by checking
if there is any element which is equal to the desired sum-curret value as this would be the va;ue which would give the required sum with the 
current element*/



int findpair(TreeNode* root,set<int> &s,int B){
    if(!root)
        return 0;
    if(s.find(B-root->val)!=s.end())
        return 1;
    s.insert(root->val);
    return max(findpair(root->left,s,B),findpair(root->right,s,B));
 }
 
int Solution::t2Sum(TreeNode* A, int B) {
    set<int> s; //using set to store seen element
    return findpair(A,s,B);
}
