/**************************************************************************************************************************************
Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].
If there is no solution possible, return -1.

Example :
A : [3 5 4 2]
Output : 2 
for the pair (3, 4)
----------------------------------------------------------------------------------------------------------------------------------------
Approach : At any index (say p) of the array we don't consider it suitable i if there are other smaller on the left side of this element
same we would not conside it suitable for j if there are elements greater than the A[j] on the right side, in order to make sure this we
make two auxillary arrays Lmin and Rmin. Now traverse the A from left to right and fill Lmin such that Lmin[p] contains smallest element
in the left of the i including p. Similarly fill Rmax such that Rmax[p] contains greatest element form p to last including p. Now just
traverse Rmax and Lmin from left to right and if Lmin[i]<Rmax[j] then calculate the diff and increase in Rmax otherwise proceed with
Lmin.
***************************************************************************************************************************************/
int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    vector<int> Lmin(n), Rmax(n);
    
    Lmin[0]=A[0];
    for(int i=1;i<A.size();i++)
        Lmin[i]=min(L[i-1],A[i]);
    
    Rmax[n-1] = A[n-1];
    for(int i=A.size()-2;i>=0;i--)
        Rmax[i]=max(R[i+1],A[i]);
    
    
    int i=0, j=0, ans=-1;
    while(i<A.size() && j<A.size())
    {
        if(Lmin[i]<=Rmax[j])
        {
            ans=max(ans, j-i);
            j++;
        }
        else
            i++;
    }
    return ans;
    
}
