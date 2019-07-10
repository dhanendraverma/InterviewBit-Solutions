/**************************************************************************************************************************************
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note: Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets. For example, given array S = {-1 0 1 2 -1 -4}, A solution set is:
(-1, 0, 1)
(-1, -1, 2) 
----------------------------------------------------------------------------------------------------------------------------------------
Appraoch :
Sort the array and traverse each element one by one. Consider two pointers l starting just after the element and r starting from the end
of the array. Now check if sum = A[i](cuurent)+A[l]+A[r] is equal to zero. if sum is greater then the 0 move the r pointer to get the 
lower values otherwise move l fot the higher values. If it's exactly equal to zero then we push into temp in order A[i], A[l]. A[r] 
since A is sorted so this order will definitely sorted. Use a set data strucutre to avoid repeatations we check if triplets already
exists in the mp then don't push it into the ans. We also check for A[i] and A[i-1] are similar or not this since we have checked all 
the for all the triplets for A[i-1] don't need to check for A[i].
***************************************************************************************************************************************/

vector<vector<int> > Solution::threeSum(vector<int> &A) {
    sort(A.begin(), A.end());
    int n = A.size();
    vector<vector<int> > ans;
    vector<int> temp;
    set<vector<int> > mp;
    int l,r;
    for (auto i = 0; i<n-2; ++i)
    {
        l = i+1; 
        r = n-1;
        
        if (i>0 && A[i]==A[i-1]) 
            continue;
            
        while(l<r)
        {
            auto sum = A[i]+A[l]+A[r];
            if(sum==0)
            {
                temp.push_back(A[i]);
                temp.push_back(A[l]);
                temp.push_back(A[r]);
                if(mp.find(temp)==mp.end()) {
                    mp.insert(temp);
                    ans.push_back(temp);
                }
                ++l; --r;
                temp.clear();
            }
            else if(sum>0)
                --r;
            else
                ++l;
        }
    }
    return ans;
}
