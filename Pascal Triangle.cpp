/**************************************************************************************************************************************
Given numRows, generate the first numRows of Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Given numRows = 5,

Return

[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]

----------------------------------------------------------------------------------------------------------------------------------------
Appraoch : 
If we draw the pascal triangle in paper then we can observe some properties of the triangle.
1.The number of elements in the rows is exactly equal to the row number.
2.First and last element in all the rows are 1.
3.Rest of the elements in a row are sum of the two elements from the row just above the current one. One will be the same column and
another one is the current column minus 1.
                by using these properties ad two loops we can now easily draw the triangle.
***************************************************************************************************************************************/                



vector<vector<int> > Solution::solve(int A) {
     vector<vector<int>>  ans(A);
    for(int i=0;i<A;i++) {
        for(int j=0;j<=i;j++) {
            if(j==0 || j==i)
                ans[i].push_back(1);
            else
                ans[i].push_back(ans[i-1][j-1]+ans[i-1][j]);
        }
    }
    
    return ans;
}
