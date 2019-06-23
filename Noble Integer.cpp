/******************************************************************************************************************************************
Sort the array and traverse the array from left to right. For every element check if element at index i is equal to (n-1-i) where n is 
total number of elements now since we are subtracting current index from the index of the last element we would get the number of elements
which are greater than current element. Corner cases can include the case where number at current index i and value at index i+1 are equal
in such just continue with checking. When there are only negative numbers and 0 in such case after sorting 0 would be at the last index
check for this condition also.
******************************************************************************************************************************************/


int Solution::solve(vector<int> &A) {
    int n = A.size();
    sort(A.begin(), A.end());
    for(int i=0;i<n;i++) {
        if(A[i] == (n-1-i) && A[i]!=A[i+1]) 
            return 1;
    }
    if(A[n-1]==0)
        return 1;
    return -1;
}
