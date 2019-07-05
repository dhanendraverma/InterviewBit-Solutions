

int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
        int diff = INT_MAX;
        
        int i = A.size()-1;
        int j = B.size()-1;
        int k = C.size()-1;

        while (i!=0 && j!=0 && k!=0) {
            int maximum = max(A[i], max(B[j], C[k]));
            int minimum = min(A[i], min(B[j], C[k]));

            if (abs(maximum - minimum) < diff) {
                diff = abs(maximum - minimum);
            }

            if (diff == 0) break;

            if (A[i] == maximum) i--;
            else if (B[j] == maximum) j--;
            else k--;
            cout<<i<<j<<k<<endl;
        }

        return diff;
}
