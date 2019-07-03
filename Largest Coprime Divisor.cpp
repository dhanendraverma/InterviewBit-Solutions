/*****************************************************************************************************************************************
You are given two positive numbers A and B. You need to find the maximum valued integer X such that:

X divides A i.e. A % X = 0
X and B are co-prime i.e. gcd(X, B) = 1
For example,

A = 30
B = 12
We return
X = 5
------------------------------------------------------------------------------------------------------------------------------------------
Approach :
The approach is simple just try to remove to all the common factors of A and B from A by dividing the A from gcd of A and B. This helps us 
to satisfy first condition i.e. A%X=0 since for the second condition repeat the procedure till gcd(A,B)!=1 these make sure that the we get
a number which is coprime with B and there is no reamaining factor of this with A and we are reducing the number from the larger ones hence
ans would be maximum.
******************************************************************************************************************************************/

int Solution::cpFact(int A, int B) {
    while(__gcd(A,B)!=1){
        A=A/__gcd(A,B);
    }
    return A;
}
