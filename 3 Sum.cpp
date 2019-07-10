/**************************************************************************************************************************************
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
Return the sum of the three integers.
Assume that there will only be one solution

Example: 
given array S = {-1 2 1 -4}, 
and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)
----------------------------------------------------------------------------------------------------------------------------------------
Approach :
We have consider the triplets but if we sort the array this reduces the complexity from O(n^3) to O(n^2). Sort array and consider each
element one by one. For each element take two pointers l which starts from just after the element and r which starts from the end of the
array. Now calculate the temporary sum of the cuurent, lth element and rth element and campare it's diff with B is minimum or not and
update the result accordingly. Now if temporary sum is less then B then we move the l pointer so get bigger values otherwise we move r
pointer for lower values. We start the l just after the element as element before this have already been considered.
***************************************************************************************************************************************/





int Solution::threeSumClosest(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    int sum, minDiff = INT_MAX;
    int n = A.size(), l, r;
    int tempSum, tempDiff;
    for(int i=0; i<n-2; i++){
        l = i+1;
        r = n-1;
        while(r > l){
            tempSum = A[i]+A[l]+A[r];
            tempDiff = abs(tempSum-B);
            if(tempDiff < minDiff) {
                minDiff = tempDiff;
                sum = tempSum;
            }
            if(tempSum < B) 
                l++;
            else
                r--;
        }
    }
    return sum;
}
