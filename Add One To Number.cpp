vector<int> Solution::plusOne(vector<int> &A) {
    int n=A.size(),carry=1; //Initialized carry 1 as we have to add 1 to given no
    int i=n-1;
    while(n--)
    {
        if(A[i]+carry>9) //if current value at index and previous carry sum is greater than 9 ,
                         //this can be max 9+1 as we just have to add 1 only
        {
            A[i]=0;
            carry=1;
        }
        else
        {
            A[i] = A[i]+carry;
            carry = 0;
        }
        i--;
    }
    if(carry)
         A.insert(A.begin(), 1); //if righmost position causes a carry then no digits will be increased insert 1 at 1st position

   while(*A.begin() == 0){
        A.erase(A.begin()); // input like 0 1 2 3 can be valid input but there should not be any preceding 0 in output
    }
    return A;
}
