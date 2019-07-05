/***************************************************************************************************************************************
Given three sorted arrays A, B and Cof not necessarily same sizes.
Calculate the minimum absolute difference between the maximum and minimum number from the triplet a, b, c such that a, b, c belongs 
arrays A, B, C respectively.
i.e. minimize | max(a,b,c) - min(a,b,c) |.

Example :
Input:
A : [ 1, 4, 5, 8, 10 ]
B : [ 6, 9, 15 ]
C : [ 2, 3, 6, 6 ]

Output:
1

Explanation: We get the minimum difference for a=5, b=6, c=6 as | max(a,b,c) - min(a,b,c) | = |6-5| = 1.
---------------------------------------------------------------------------------------------------------------------------------------
Approach:
We have to minimize |max(a,b,c)-min(a,b,c)| in order to do so there are two ways value of max(a,b,c) should be minimum possible and 
value of min(a,b,c) should be maximum possible which would cause the difference of the two to get reduced. Now as given arrays are 
sorted we start from the largest possible values of a,b,c which are the last elements of each array now at every step he possible ways
to decrease the differece is to decrease maximum element out of all three so we check which array is presently giving the max element
and get the next lower element from that array by reducing its index value. Keep repeating untill one of the any run out of elements
every update the ans.
***************************************************************************************************************************************/

int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
        int ans = INT_MAX;
        int i = A.size()-1, j = B.size()-1, k = C.size()-1;

        while (i!=0 && j!=0 && k!=0) {
            int maximum = max(A[i], max(B[j], C[k]));
            int minimum = min(A[i], min(B[j], C[k]));

            if (abs(maximum - minimum) < diff) {
                diff = abs(maximum - minimum);
            }

            if (diff == 0) break;

            if (A[i] == maximum)
                i--;
            else if (B[j] == maximum)
                j--;
            else 
                k--;
        }

        return ans;
}
