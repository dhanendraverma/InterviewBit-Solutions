bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    sort(arrive.begin(),arrive.end());
    sort(depart.begin(),depart.end());
    int i=0,j=0,count=0;
    while(i<depart.size() && j<arrive.size()) {
        if(arrive[i]<depart[j]) {
            count++;
            i++;
            if(count>K)
                return false;
        }
        else {
                j++;
                count--;
        }
        
    }
    return true;
    
}
