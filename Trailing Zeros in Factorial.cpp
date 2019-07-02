/*****************************************************************************************************************************************
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

Example :

n = 5
n! = 120 
Number of trailing zeros = 1
So, return 1
-----------------------------------------------------------------------------------------------------------------------------------------
Approach:
In order to find the no of zero in factorial we need to check how many pairs of 2 and 5 are there since there are these two prime fator
which will produce zero by multiply. Now we know that the factorial experssion is number is decreased by one and are multiplied e.g.
5!=5*4*3*2*1 so this is clear that no of 2s will always will be equal or greater than the no of 5 hence it's suffficient to count the no
of 5 to get the no of trailing zeros. Now we can count no of 5 by floor(number/5). But there are numbers where you will get 25,125 in their
factorial expression. These no also have factor of 5 which are more than once hence we divide 25 and 125 and so on to get those extra 5s.
*****************************************************************************************************************************************/

int Solution::trailingZeroes(int A) {
    int count = 0;
    for(int i=5;A/i>=1;i*=5)
        count += A/i;
    return count;
}
