/**************************************************************************************************************************************
Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.

Example:
Input: 	
1 2 3
4 5 6
7 8 9

Return the following :
[ 
  [1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]
]
---------------------------------------------------------------------------------------------------------------------------------------
Appraoch :
When we have r rows and c columns the numbers of elements in the diagonalOrder matrix becomes r+c-1 for this case since r=c=n hence
total size of matrix would be (2*n-1). Now we can see in the example above that the first each element from the first row is taken
and starting from there we move downwards diagonally back means we incearse rows number r and decreases the column number c and keep
storing them in the current list untill we touch lowest or the leftmost index. Similary if we are done with the first row elements
we do this for all the elements for the last col and starting from there we move downwards diagonally back. we just take care of the 
1st row last col since this is the part of first row and and last col that's why we start from 2nd element(index 1) in the last
otherwise this will be accounted twice.
***************************************************************************************************************************************/

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n = A.size();
    vector<vector<int>> diagonalOrder(2*n-1);
    int index = 0;
    for(int i=0;i<n;i++){
        int r=0,c=i;
        while( r<n && c>=0 ){
            diagonalOrder[index].push_back(A[r][c]);
            r++;
            c--;
        }
        index++;
    }
    
    for(int i=1;i<n;i++){
        int r=i,c=n-1;
        while( r<n && c>=0 ){
            diagonalOrder[index].push_back(A[r][c]);
            r++;
            c--;
        }
        index++;
    }
    return diagonalOrder;
}
