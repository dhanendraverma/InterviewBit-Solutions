/*****************************************************************************************************************************************
Given a column title as appears in an Excel sheet, return its corresponding column number.

Example:

    A -> 1
    
    B -> 2
    
    C -> 3
    
    ...
    
    Z -> 26
    
    AA -> 27
    
    AB -> 28 
------------------------------------------------------------------------------------------------------------------------------------------
Approach:
The conversion is similar to the binary to decimal conversion as each position in binary digit can take any of the ten values(0-9) and 
when you move with higher bit position each postion can serve 10 more combination and power of 10 get increases similiary here each 
position can take 26 values. When we go to with higher position i.e. on the left side the power of 26 will inceases as they will from 
another 26 combinations. Trace the string from the left to right and get it's int value and add it to the ans when you again move left
side multiply previous ans with 26 then again add int value.
******************************************************************************************************************************************/

int Solution::titleToNumber(string A) {
    int ans = 0;
    for(int i=0;i<A.length();i++) {
        ans = ans*26;
        ans = ans+(A[i]-'A'+1);
    }
    return ans;
}
