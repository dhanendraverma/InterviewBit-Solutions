
nt Solution::maxSubArray(const vector<int> &A) {
    //using Kadane’s Algorithm
    int max_sum = A[0], max_till = A[0]; //max_sum will give max subarray sum
                                        //max_till is the max seen till ith index upon adding all the elements
    for(int i=1;i<A.size();i++)
    {
        max_till = max(A[i],A[i]+max_till); //when negative elements are encountered sum can be less then the no itself
        max_sum = max(max_sum,max_till);  //max_sum is the maximum of all the sum ending at ith index

    }
    return max_sum;
}
