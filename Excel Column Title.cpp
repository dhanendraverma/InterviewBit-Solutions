/******************************************************************************************************************************************
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
------------------------------------------------------------------------------------------------------------------------------------------
Appraoch : Take the remainder wiht 26 if remainder is 0 then we need to add Z in the string otherwise need to convert the int into char by
adding A. If remainder is 0 we need to make the number n = n/26-1 beacause relatively it's 25th with respect to A but we have considered 
it at 26th place. For other remainders n will be n = n/26.
******************************************************************************************************************************************/


string Solution::convertToTitle(int n) {
    string ans="";
    while(n){
        int rem=n%26;
        if(rem==0) {
            ans.push_back('Z');
            n=n/26-1;
            
        }
        else{
            ans.push_back(char(rem-1+'A'));
            n=n/26;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
