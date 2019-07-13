/***************************************************************************************************************************************
Write an efficient algorithm that searches for a value in an m x n matrix.
This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than or equal to the last integer of the previous row.

Example:
Consider the following matrix:
[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return 1 ( 1 corresponds to true )

Return 0 / 1 ( 0 if the element is not present, 1 if the element is present ) for this problem
----------------------------------------------------------------------------------------------------------------------------------------
Approach:
The first task to solve this problem is two find the right the row. In order to find the correct row we start checking from 0th row and
check for each row that the desired key lies between the start and end of the row. If this condition is true the second task is to run a
binary search in that row and return  if founf else 0. This return value decide wether key exists in the matrix or not.
***************************************************************************************************************************************/


int binarySearch(vector<int> A, int start, int end, int key){
    while(start <= end) {
        int mid = start + (end-start)/2;
        if(A[mid] == key)
            return 1;
        else if(A[mid] > key)
            end = mid-1;
        else
            start = mid+1;
        }
    return 0;
}

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int row = A.size();
    int col = A[0].size();
    for(int i = 0; i < row; i++){
        if((A[i][0]<=B) && (A[i][col-1] >= B)) {
            if(binarySearch(A[i], 0, col-1, B))
                return 1;
            else
                return 0;
        }
    }
    return 0;
}
