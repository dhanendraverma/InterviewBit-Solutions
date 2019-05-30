
/*in order to find the max value of |A[i] - A[j]| + |i - j|
*   max value of A[i]+i can be subtracted with the min value of the A[j]+j
*   (A[i]+i-A[j]+j) = A[i]-A[j]+(i-j)
*   max value of A[i]-i can be subtracted with the min value of the A[j]-j
*   (A[i]-i)-(A[j]-j) = A[i]-A[j]+(j-i)
*/


int Solution::maxArr(vector<int> &A) {
    int sum = INT_MIN, max1 = INT_MIN, max2 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX; //initializing values
    for (int i = 0; i < A.size(); ++i)
    {
        max1 = max(max1, A[i] + i);
        min1 = min(min1, A[i] + i);
        max2 = max(max2, A[i] - i);
        min2 = min(min2, A[i] - i);
    }
    sum = max(max1-min1, max2-min2);
    return sum;
}
