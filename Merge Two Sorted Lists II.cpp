/***************************************************************************************************************************************
Given two sorted integer arrays A and B, merge B into A as one sorted array.

 Note: You have to modify the array A to contain the merge of A and B. Do not output anything in your code.
TIP: C users, please malloc the result into a new array and return the result. 
If the number of elements initialized in A and B are m and n respectively, the resulting size of array A after your code is 
executed should be m + n

Example :

Input : 
         A : [1 5 8]
         B : [6 9]

Modified A : [1 5 6 8 9]
---------------------------------------------------------------------------------------------------------------------------------------
Approach : Take two pointers i and j.i will point a location in A and j will point for B. Now traverse both the array untill one of them 
is exhausted. At each step check if A[i]>=B[i] in such case we need to add smaller one that iss B[j] to add into to A at the current 
index and increase now i and j for next element. If A[i]<B[j] then smaller one is at correct place and compare with next element in B.
At last check if there are any reamining elements in B since they can be larger then the largest no in the list A hence those are needed
to append at the last of the A.
***************************************************************************************************************************************/

void Solution::merge(vector<int> &A, vector<int> &B) {
  while(i<A.size() && j<B.size()) {
        if(A[i]>=B[j]) {
            A.insert(A.begin()+i,B[j]);
            i++;
            j++;
        }
        else if(A[i]<B[j]){
            i++;
        }
    }
    while(j<B.size()){
            A.push_back(B[j]);
            j++;
        }
    
}
