*****************************************************************************************************************************************/
Determine whether an integer is a palindrome. Do this without extra space.

A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed.
Negative numbers are not palindromic.

Example :

Input : 12121
Output : True

Input : 123
Output : False
-----------------------------------------------------------------------------------------------------------------------------------------
Appraoch : Convert the integer into a string. Now check if first half of the string is equal to the second half or not. If at any point
elements at the index i and (n-1-i) are not equal then return false otherwise return true.
******************************************************************************************************************************************/

int Solution::isPalindrome(int A) {
    string s = to_string(A);
    int n = s.size();
    
    for(int i=0;i<n/2;i++) {
        if(s[i]!=s[n-i-1])
            return 0;
        
    }
    return 1;
}
