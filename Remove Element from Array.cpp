/*****************************************************************************************************************************************
Given an array and a value, remove all the instances of that value in the array. 
Also return the number of elements left in the array after the operation.
It does not matter what is left beyond the expected length.

Example:
If array A is [4, 1, 1, 2, 1, 3]
and value elem is 1, 
then new length is 3, and A is now [4, 2, 3] 
Try to do it in less than linear additional space complexity
------------------------------------------------------------------------------------------------------------------------------------------
Approach:
Traverse the array with the two pointers i and j, both starting at the index 0. Now we check if the current element which will we at jth
index is equal to the element to be deleted if yes then we leave it as it's otherwise we copy the element to the ith index and increase it
to point to the next location where next non B element should be copied. At last we erase all the element after i since out of those which
are non B have already copied and rest are equal to B.
*****************************************************************************************************************************************/

int Solution::removeElement(vector<int> &A, int B) {
    int i = 0,j=0;
    int n = A.size();
    while(j < n) {
        if(A[j] != B) {
            A[i] = A[j];
            i++;
            
        }
        j++;
    }
    A.erase(A.begin()+i,A.end());
    return i;
    
}
