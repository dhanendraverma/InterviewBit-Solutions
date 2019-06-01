/*---------------------------------------------------------------------------------------------------------------------------|
|Given an array of numbers from 1 to n on number A is missing and B is repeated. FInd out both the numbers,                   |
|Since sum of n numbers S = 1+2+-----+A+B+n = n*(n+1)/2                                                                       |
|Since sum of square of n numbers SQ = 1+2+-----+A+B+n = n*(n+1)*(2n+1)/2                                                     |
|Let the sum we get by using given no is S1 = 1+2+---B+B+n (A is missing and B is repeated)                                   |
|Let the sum we get by using square of given no is SQ1 = (1^2)+(2^)+---(B^2)+(B^)+(n^2) (A is missing and B is repeated)      |
|    S-S1 = A-B                                                                                                           |
|    SQ-SQ1 = A^2-B^2 = (B+A)(A-B) => B+A = (SQ-SQ1)/(A-B) = (SQ-SQ1)/S-S1)                                             |
|    using above two euquations                                                                                               |
|    upon addition of these two equation 2A = (SQ-SQ1)/(S-S1)+(S-S1)                                                         |
|    Similarly by subtracting these two equations                                                                   |
|    2B = (S-S1)-(SQ-SQ1)/(S-S1)                                                                                                          |
|-----------------------------------------------------------------------------------------------------------------------------|
*/

#define ll long long


vector<int> Solution::repeatedNumber(const vector<int> &A) {

ll n=A.size();
    ll S1=0;
    ll SQ1=0;
    for(ll i=0;i<n;i++)
    {
        S1 += A[i];
        SQ1 += ((ll)A[i]*(ll)A[i]);
    }

    ll S = (n*(n+1)/2);

    ll SQ = ((n*(n+1)*(2*n+1))/6);

    ll temp = (SQ-SQ1)/(S-S1);

    int repeated = (temp-(S-S1))/2;

    int missing = ((S-S1)+temp)/2;

    vector<int> ans;

    ans.push_back(repeated);
    ans.push_back(missing);

    return ans;
}
