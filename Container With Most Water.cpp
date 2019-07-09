/*****************************************************************************************************************************************
Given n non-negative integers a1, a2, ..., an,
where each represents a point at coordinate (i, ai).
'n' vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).

Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Your program should return an integer which corresponds to the maximum area of water that can be contained 
( Yes, we know maximum area instead of maximum volume sounds weird. But this is 2D plane we are working with for simplicity ).

 Note: You may not slant the container. 
Example :

Input : [1, 5, 4, 3]
Output : 6

Explanation : 5 and 3 are distance 2 apart. So size of the base = 2. Height of container = min(5, 3) = 3. 
So total area = 3 * 2 = 6
----------------------------------------------------------------------------------------------------------------------------------------
Approach :
In order to get the area we'll multiply base(the distance on the X-axis or the differece between the two indexes) with the min of the 
two vertical line hights as we can fill the water till the minumum hight only. So container area between i & j becomes 
base*min(A[i], A[j]). Now we have to fine those points i & j for which the value of area will be max. As we also have to keep the base
maximum we start  from the maximum base value i.e. 0th and the last index and we then shrink that window depending upon which side
reduction gives us the more hight so more water can be contained.
****************************************************************************************************************************************/


int Solution::maxArea(vector<int> &A) {
    int l = 0;
    int r = A.size()-1;
    int ans = 0;
    
    while(l < r) {
        ans = max(ans,min(A[l],A[r])*(r-l));
    if(A[l]<A[r])
        l++;
    else
        r--;
    }
    return ans;
}
