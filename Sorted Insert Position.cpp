/**************************************************************************************************************************************
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were 
inserted in order.
You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
----------------------------------------------------------------------------------------------------------------------------------------
Approach : 
We run a binary search till in a while loop till we find the correct position. We set the start to 0th and end to the last index. Every
time we calculate mid position between this two. Now we compare the mid value with the desired one if the mid is greater than the value 
in such case we search in left half i.e. we set the end to the mid-1 otherwise if it's less in that case we search in right half i.e. 
set the starting to the mid+1, if the mid is exactly euale the value then we are done and return mid position. At any point if we are
done with all the elements in such case the put bisect window will be 0 and start and ending would be same. In such case we check 
if the value is greater then current starting=ending then return start+1, else start would be corract position.
***************************************************************************************************************************************/

int Solution::searchInsert(vector<int> &A, int x) {
    int start = 0, end = A.size()-1;
    while(true) {
        if(start==end)
        {
            if(x>A[start])
                return start+1;
            else
                return start;
        }
    int mid=(start+end)/2;
    if(A[mid]==x)
        return mid;
    else if(x<A[mid])
        end = mid;
    else
        start = mid+1;
        
    }
}
