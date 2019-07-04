/****************************************************************************************************************************************
Find the intersection of two sorted arrays.
OR in other words,
Given 2 sorted arrays, find all the elements which occur in both the arrays.

Example :

Input : 
    A : [1 2 3 3 4 5 6]
    B : [3 3 5]

Output : [3 3 5]

Input : 
    A : [1 2 3 3 4 5 6]
    B : [3 5]

Output : [3 5]
 NOTE : For the purpose of this problem ( as also conveyed by the sample case ), assume that elements that appear more than once in
 both arrays should be included multiple times in the final output. 
 ----------------------------------------------------------------------------------------------------------------------------------------
 Approach :Traverse the array untill one of the exhausted using two pointers i and j. At any point if elemnet in A and B are equal add that
 to the answer list (A[i]==B[j]), else increase the index of the smaller element list's index to compare the next elements.
 *****************************************************************************************************************************************/
 vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    vector<int> ans;
    int i=0,j=0;
    while(i<A.size() && j<B.size()) {
        if(A[i]==B[j]) {
            ans.push_back(A[i]);
            i++;
            j++;
        }
        else if(A[i]<B[j])
            i++;
        else
            j++;
    }
    return ans;
}
