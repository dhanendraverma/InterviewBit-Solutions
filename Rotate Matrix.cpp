/* We can't use extra space this would give only the partial score. The best to solve this problem is using inplace method. Just try it 
yourself by drwaing a matrix in a paper a how elements get placed when you rotate the array 90 degree clockwise.The leftmost and uppermost 
corner will become rightmost,uppermost element and element next to former would come below the later one just keep drwaing this and soon
you'll get the intution behind this*/


void Solution::rotate(vector<vector<int> > &A) {
   int n = A.size();
        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < n - i - 1; j++) {
            int x = A[i][j];
            A[i][j] = A[n - j - 1][i];
            A[n - j - 1][i] = A[n - i - 1][n - j - 1];
            A[n - i - 1][n - j - 1] = A[j][n - i - 1];
            A[j][n - i - 1] = x;
            }
        }
}
