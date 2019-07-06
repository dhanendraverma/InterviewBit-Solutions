
int count = 0;          // Just moving duplicates at back of vector approach, faster;
    int size = A.size();
    for(auto i = 0; i<size; ++i)
    {
        if(i<size-2 && A[i]==A[i+1] && A[i]==A[i+2]) continue;
        else
            A[count++] = A[i];
    }
    return count;
