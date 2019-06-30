******************************************************************************************************************************************
Reverse digits of an integer.

Example1:

x = 123,

return 321
Example2:

x = -123,

return -321

Return 0 if the result overflows and does not fit in a 32 bit signed integer
------------------------------------------------------------------------------------------------------------------------------------------
Approach : Take a long int this can accomodate 64 bit int. Now from the back side take one by one digit and add this to the ans. Everytime
check if the value falls down below min value of the 32 bit int or rises above max int then return 0 otherwise cast the long into int and
return ans.
*****************************************************************************************************************************************/

int Solution::reverse(int A) {
    long long  ans=0;
    while(A) {
        ans = ans*10+A%10;
        A = A/10;
        if(ans>INT_MAX || ans<INT_MIN)
            return 0;
    }
    
    return int(ans);
        
}
