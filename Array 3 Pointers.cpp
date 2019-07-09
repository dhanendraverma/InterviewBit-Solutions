/**************************************************************************************************************************************
You are given 3 arrays A, B and C. All 3 of the arrays are sorted.

Find i, j, k such that :
max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized.
Return the minimum max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i]))

**abs(x) is absolute value of x and is implemented in the following manner : **
if (x < 0) return -x;
else return x;

Example :
Input : 
        A : [1, 4, 10]
        B : [2, 15, 20]
        C : [10, 12]
Output : 5 
         With 10 from A, 15 from B and 10 from C.
---------------------------------------------------------------------------------------------------------------------------------------
Approach : This question is just the anothe variant of the Minimize the absolute difference : 
https://www.interviewbit.com/problems/minimize-the-absolute-difference/
Now there we have been asked to fine the minumum value of (max(a,b,c)-min(a,b,c)). In the above question we have to find the minimum 
value of the max(a-b,b-c,c-a) where all differece are abs. When we have to find the max value of the difference the one value should be
maximum possible and one should be minimum possible in such case only differene will be maximum. So at each step we have to find the
those two values i.e. one max and anotheris min. We take triplets find the max and min out of them and calculate the difference compare
it with previou diff. Now in order to minimize this diff we have to reduce the max value and we do this we going down in the indexes 
in the array which give the max element.
***************************************************************************************************************************************/

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int diff = INT_MAX;
    int i = A.size()-1;
    int j = B.size()-1;
    int k = C.size()-1;

    while (i!=-1 && j!=-1 && k!=-1) {
        int maximum = max(A[i], max(B[j], C[k]));
        int minimum = min(A[i], min(B[j], C[k]));
        if (abs(maximum - minimum) < diff) {
            diff = abs(maximum - minimum);
        }

        if (diff == 0) break;
        if (A[i] == maximum) i--;
        else if (B[j] == maximum) j--;
        else k--;
        
    }

    return diff;
}
