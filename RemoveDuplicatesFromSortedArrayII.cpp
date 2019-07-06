/*****************************************************************************************************************************************
Given a sorted array, remove the duplicates in place such that each element can appear atmost twice and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.

Note that even though we want you to return the new length, make sure to change the original array as well in place
For example,
Given input array A = [1,1,1,2],
Your function should return length = 3, and A is now [1,1,2]
------------------------------------------------------------------------------------------------------------------------------------------
Approach:
Traverse the arry and use two pointers i which indicates the index of the current position to be checked and the j which helps to modify 
the original array inplace. Now whenever we see the three consequetive same elements like 2,2,2,3,3 here 2 is repeated three times and the
if condition inside e loop is true and we do not copy ith element while we go next next two 2's will get cpoied even if there are more 
than 3 repeatations only last two will get copied.
*****************************************************************************************************************************************/

int Solution::removeDuplicates(vector<int> &A) {
    int j = 0;         
    int size = A.size();
    for(auto i = 0; i<size; ++i)
    {
        if(i<size-2 && A[i]==A[i+1] && A[i]==A[i+2]) 
            continue;
        A[j++] = A[i];
    }
    A.erase(A.begin()+j,A.end());
    return j;
}
