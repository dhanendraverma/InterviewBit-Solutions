/*---------------------------------------------------------------------------------------------------------------------------|
|Given an array of numbers from 1 to n on number A is missing and B is repeated. FInd out both the numbers,                   |
|Since sum of n numbers S = 1+2+-----+A+B+n = n*(n+1)/2                                                                       |
|Since sum of square of n numbers S2 = 1+2+-----+A+B+n = n*(n+1)*(2n+1)/2                                                     |
|Let the sum we get by using given no is S' = 1+2+---B+B+n (A is missing and B is repeated)                                   |
|Let the sum we get by using square of given no is S2' = (1^2)+(2^)+---(B^2)+(B^)+(n^2) (A is missing and B is repeated)      |
|    S' - S = B - A                                                                                                           |
|    S2' - S2 = B^2 - A^2 = (B+A)(B-A) => B+A = (S2'-S2)/(B-A) = (S2'-S2)/(S'-S )                                             |
|    using above two euquations                                                                                               |
|    upon addition of these two equation 2B = (S'-S)+(S2'-S2)/(S'-S )                                                         |
|    Similarly we can find A by using any of the equation                                                                     |
|    A  = B - (S'-S)                                                                                                          |
|-----------------------------------------------------------------------------------------------------------------------------|
*/

#define ll long long


vector<int> Solution::repeatedNumber(const vector<int> &A) {

ll n=A.size(), S'=0, S2'=0;

    for(ll i=0;i<n;i++)
    {
        S'+=(ll)A[i];
        S2'+=((ll)A[i]*(ll)A[i]);
    }

    ll S = (n*(n+1)/2);

    ll S2 = ((n*(n+1)*(2*n+1))/6);

    ll temp = (S2'-S2)/(S'-S );

    int repeated = (temp+(S'-S))/2;

    int missing = repeated - (S'-S);



    vector<int> ans;

    ans.push_back(repeated);
    ans.push_back(missing);

    return ans;
}
