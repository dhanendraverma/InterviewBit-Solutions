/****************************************************************************************************************************************
Given an index k, return the kth row of the Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Input : k = 3

Return : [1,3,3,1]
------------------------------------------------------------------------------------------------------------------------------------------
Approach:
Since all the rows in pascal triangle are the indication for the binomial expression cofficient we can calculate each term by using the 
formula for the same. However don't need to considee the whole factorial term just multiply the previous term with the factor which would
come into picture when next term in cofficients are calculated. But we save half calculations as it repeates from the half. So just 
calculate the first half and copy these values for next half.
*****************************************************************************************************************************************/

vector<int> Solution::getRow(int n) {
  std::vector<int> row(n+1);
    row[0] = 1; 
    for(int i=1; i<n/2+1; i++){ 
        row[i] = row[i-1] * (n-i+1)/i;
    }
    for(int i=n/2+1; i<=n; i++){
        row[i] = row[n-i];
    }
        
    return row;
}
