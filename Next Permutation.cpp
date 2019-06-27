/***************************************************************************************************************************************
Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers.

If such arrangement is not possible, it must be rearranged as the lowest possible order ie, sorted in an ascending order.

The replacement must be in-place, do not allocate extra memory.

Examples:

1,2,3 → 1,3,2

3,2,1 → 1,2,3

1,1,5 → 1,5,1

20, 50, 113 → 20, 113, 50
----------------------------------------------------------------------------------------------------------------------------------------
Approach :
When we have to findthe next permutation the first thing come into mind is to change smallest from the last should be swappped with the
next smallest. Traverse the array from the back side and find the element which is smaller than the just previous element. If we don't 
find such element that mean elements are already arranged in an order which is biggest lexographically. Now suppose we find such element
at index (i-1). Now we have to find an element to the right of this which is just greater or next smaller than this element we also 
check each element should be less than A[i] otherwise A[i] would be missed as then can also be nexts. Now just swap the A[i-1 with nexts
and sort element right to this. Now this wold make the array lexographically small.
***************************************************************************************************************************************/

void Solution::nextPermutation(vector<int> &A) {
    int i;
    for(i=A.size()-1;i>0;i--)
    {
        if(A[i]>A[i-1])
            break;
        
    }
    if(i==0)
    {
        sort(A.begin(),A.end());
        return ;
    }
    
    int nexts = i;
    for(int j=A.size()-1; j>i; j--)
    {
        if(A[j]>A[i] && A[j]<A[nexts])
            nexts=i;
    }
    swap(A[nexts],A[i-1]);
    sort(A.begin()+i,A.end());
}
