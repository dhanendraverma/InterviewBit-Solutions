/*****************************************************************************************************************************************
Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.
NOTE A solution will always exist. read Goldbach’s conjecture

Example:
Input : 4
Output: 2 + 2 = 4

If there are more than one solutions possible, return the lexicographically smaller solution.

If [a, b] is one solution with a <= b,
and [c,d] is another solution with c <= d, then
[a, b] < [c, d] 
If a < c OR a==c AND b < d. 
-----------------------------------------------------------------------------------------------------------------------------------------
Appraoch : Whever there is a question appears related to prime number the first thing come into mind is "Sieve of Eratosthenes". This is
It's a simple algorithm. We know the first that the first prime no is 2 and then we mark all the composite numbers which are multiple
of 2 because they are surely divisble by 2 similary we set a loop which iterate over the elements till the number which we want to check
prime number, now we use an inner loop which mark all the elements which are multiple of current outer loop element. Next the task is 
simple starting from 2 check if any element(say i) is prime and (A-i) is prime if both are prime means we have found our ans since they 
add up to make n and they both are prime also since we are checking from 2 and increasing one by one so this would be the leographically
smallest.
******************************************************************************************************************************************/

vector<int> Solution::primesum(int A) {
    vector<bool> prime(A+1,true);
    for(int p=2;p*p<=A;p++) {
        if(prime[p]==true) {
            for(int i=p*p; i<=A; i+=p)
                prime[i]=false;
        }
    }
    
    vector<int> ans;
    //cout<<prime[2]<<prime[3];
    
    for(int i=2;i<=A;i++) {
        if(prime[i]==true && prime[A-i]==true) {
            ans.push_back(i);
            ans.push_back(A-i);
            return ans;
            
        }
    }
}
