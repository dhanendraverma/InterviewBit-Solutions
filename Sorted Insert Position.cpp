int Solution::searchInsert(vector<int> &A, int x) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=A.size();
    int low=0,high=n-1;
    int mid=low+(high-low)/2;
    while(low<=high){
        mid=low+(high-low)/2;
        if(A[mid]==x||(mid==0&&x<A[mid])||(mid>0&&x<A[mid]&&x>A[mid-1]))
         return mid;
        if(x>A[mid]) low=mid+1;
        else high=mid-1;
    }
    return n;
}
