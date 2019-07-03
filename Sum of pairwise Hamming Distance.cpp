/***************************************************************************************************************************************
Hamming distance between two non-negative integers is defined as the number of positions at which the corresponding bits are different.

For example,

HammingDistance(2, 7) = 2, as only the first and the third bit differs in the binary representation of 2 (010) and 7 (111).

Given an array of N non-negative integers, find the sum of hamming distances of all pairs of integers in the array.
Return the answer modulo 1000000007.

Example

Let f(x, y) be the hamming distance defined above.

A=[2, 4, 6]

We return,
f(2, 2) + f(2, 4) + f(2, 6) + 
f(4, 2) + f(4, 4) + f(4, 6) +
f(6, 2) + f(6, 4) + f(6, 6) = 

0 + 2 + 1
2 + 0 + 1
1 + 1 + 0 = 8
---------------------------------------------------------------------------------------------------------------------------------------
Approach :
Since all the numbers are the non negative intergers they will be repesented by 32 bits in binary representation. For each bit we count 
the numbers which have binary number such that bit at that position is set. For this we run a loop from 0 to 31 at for variable i now
we shift the 1 at that position (1<<i) so we will get at binary number having only ith bit set now by doing logical and with the current
number we can get to wether current number has a bit set at that position or not. We count all the nummbers and temp variable stores
all such numbers now remaining numbers (n-temp) are the one which don't have their bit set at the ith position. Now there will be 
temp*(n-temp) such combination where one number has ith bit set and other one doesn't since every pair will be counted twice we just 
multiply this combination with 2. For all bit posiion we add the ans.
***************************************************************************************************************************************/

int Solution::hammingDistance(const vector<int> &A) {
     long long ans=0,n=A.size();
    long long temp;
    for(int i=0;i<31;i++){
        temp=0;
        for(int j=0;j<n;j++){
            if(A[j]&(1<<i))
                temp++;
        }
        ans += (temp*(n-temp)*2)%1000000007;
    }
    return ans;
}
