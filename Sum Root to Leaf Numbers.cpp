
/* use top bottom approach start from root go for left and right child while going down multiply previous sum with 10 and add current value
this will help in making a number using the digits from root to leaf path. Also keep doing mod of the number and we have to return mod value
only. Whenever reached a root return the sum and add the left and right child sum to get the total sum. by using mod again return the
value */


int rtsum(TreeNode* root, int sum){
     if(!root)
        return 0;
     sum = ((sum%1003)*10+(root->val)%1003)%1003;
     
     if(root->left==NULL && root->right==NULL)
        return sum;
     return (rtsum(root->left,sum)%1003 + rtsum(root->right,sum)%1003)%1003;
 }
 
 
int Solution::sumNumbers(TreeNode* A) {
    return rtsum(A,0);
}
