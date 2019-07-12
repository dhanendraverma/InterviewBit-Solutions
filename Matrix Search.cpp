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
    int rows = A.size();
    int cols = A[0].size();
    for(int i = 0; i < rows; i++){
        if((A[i][0]<=B) && (A[i][cols-1] >= B)) {
            if(binarySearch(A[i], 0, cols-1, B))
                return 1;
            else
                return 0;
        }
    }
    return 0;
}
