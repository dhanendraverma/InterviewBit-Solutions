int Solution::repeatedNumber(const vector<int> &A) {
    vector <bool> check(A.size(),false); //creating a boolean vector to keep tracked of seen intergers

    for(int i=0;i<A.size();i++){
        if(!check[A[i]]) //if element is seen first time marked it as seen
            check[A[i]]=true;
        else                //else it has been already
            return A[i];
    }
}
