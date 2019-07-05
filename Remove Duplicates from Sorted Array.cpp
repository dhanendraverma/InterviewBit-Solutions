/****************************************************************************************************************************************
Remove duplicates from Sorted Array
Given a sorted array, remove the duplicates in place such that each element appears only once and return the new length.

Note that even though we want you to return the new length, make sure to change the original array as well in place

Do not allocate extra space for another array, you must do this in place with constant memory.
Example: 
Given input array A = [1,1,2],
Your function should return length = 2, and A is now [1,2]. 
-----------------------------------------------------------------------------------------------------------------------------------------
Approach:
Travese the array using the two pointers i and j.i starts from 0th and j 1st. Now check if element at the two indexes are not equal then 
the element at the jth index must come after the index i hence incease the ith by one and store element there now if two elements are eual
in such case leave jth as it's as we already have a copy at ith index, increase jth index and check for next elements.At last when jth
reached the last we can delete the elements from (j+1) to last as this are these contain duplicates only.
*****************************************************************************************************************************************/

int Solution::removeDuplicates(vector<int> &A) {
    if(A.size() == 0){
        return A.size();
    }
    
    int i=0,j=1;
    while(j<A.size()){
        if(A[i] != A[j]) {
            i++;
            A[i] = A[j];
            
        }
        j++;
    }
    
    A.erase(A.begin()+i+1, A.end());
    return i+1;
    
}
