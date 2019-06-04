
vector<int> Solution::maxset(vector<int> &A) {
    int n=A.size();
    int start=0,end=-1, ansl=-1, ansr=-1, maxm=0, ele=0, maxele=0;
    long long sum=0,maxsum=0;
    vector<int> ans;
    int i=0;

    while(i<n){
        while(A[i]>=0) //loop untill negative value is encountered
        {
            sum += A[i]; //add all the consecutive  pos nos
            end++; //increase end index
            i++;
            if(i==n)
                break;
        }

        if(sum>maxsum) //current subarray sum is greater then the last one
        {
            maxsum = sum;
            ansl = start; //set ans' left index and right index
            ansr = end;
        }
        else if(sum == maxsum && (end-start+1)>maxele)  //if sum is same but no of elements
                                                        // are more in current subarray
        {
            maxele = end-start+1;
            ansl = start;
            ansr = end;
        }

        if(A[i]<0) //when negative value is encountered reset all the index
        {
            ele=0;
            start=i+1;
            end=i;
            sum=0;
        }

        i++;
    }

    if(ansl != -1 && ansr != -1){
        for(int i = ansl; i<=ansr; i++)
            ans.push_back(A[i]);
    }
    return ans;

}
