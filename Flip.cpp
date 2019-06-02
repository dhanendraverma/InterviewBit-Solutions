vector<int> Solution::flip(string A) {
    int count = 0, maxcount = 0, left=-1, right, ansleft=0, ansright=0;
    int n = A.length();
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        if(A[i]=='0') //whenevr encounter '0' increase the count of substring having 0 and set the right index at which
                      //we are getting that count
        {
            if(left<0)
                left = i+1;
            right = i+1;
            count++;

        }
        else
            count--; //whenever encounter 0 decrease count is rthe sequece
        if(count<0)  //when count goes below 0 means there are more no of ones in the substring so reset the left
                     //index to start again
        {
            count = 0;
            left = -1;

        }
        if(maxcount < count) //keep track of longest substring
        {
            ansleft = left;
            ansright = right;
            maxcount = count;

        }
    }


    if(ansleft>0)
    {
        ans.push_back(ansleft);
        ans.push_back(ansright);
    }
    return ans;
}
