int Solution::repeatedNumber(const vector<int> &A) {
    vector <bool> check(A.size(),false);

    for(int i=0;i<A.size();i++){
        if(!check[A[i]])
            check[A[i]]=true;
        else
            return A[i];
    }
}
