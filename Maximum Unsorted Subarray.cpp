vector<int> Solution::subUnsort(vector<int> &A) {
    int n=A.size();
    vector<int> ans;
    int s = -1,e = -1;
    for(int i=0;i<n-1;i++) {
        if(A[i]>A[i+1]){
            s=i+1;
            break;
        }
    }
    
    if(s == -1) {
        ans.push_back(-1);
        return ans;
    }
    for(int i=n-1; i>0; i--){
        if(A[i]<A[i-1]) {
            e=i;
            break;
        }
    }
  
    int mine = A[s], maxe = A[s];
    
    for(int i=s+1;i<=e;i++) {
        mine = min(mine, A[i]);
        maxe = max(maxe, A[i]);
    }
    for(int i=0;i<s;i++) {
        if(A[i]>mine){
         s=i;
         break;
        }
    }
    for(int i=n-1;i>e;i--) {
        if(A[i]<maxe){
         e=i;
         break;
        }
    }
    ans.push_back(s);
    ans.push_back(e);
    return ans;
}
