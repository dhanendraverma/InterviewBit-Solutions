/*****************************************************************************************************************************************
A hotel manager has to process N advance bookings of rooms for the next season. His hotel has K rooms. 
Bookings contain an arrival date and a departure date. He wants to find out whether there are enough rooms in the hotel to satisfy the 
demand. Write a program that solves this problem in time O(N log N) .
Input : 
        Arrivals :   [1 3 5]
        Departures : [2 6 8]
        K : 1

Return : False / 0 

At day = 5, there are 2 guests in the hotel. But I have only one room
----------------------------------------------------------------------------------------------------------------------------------------
Approach : sort the arrival and depart time. Now we just need to check for the overlaps means if current guest will not leave before the
next guest comes if such is the case then we need extra room for next guest otherwise we no need to allot extra room and one of room
will get vacant. Now keep count of the rooms allocated and if the number increase above K return false otherwise after processing all the
inputs case is valid return true.
******************************************************************************************************************************************/

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    sort(arrive.begin(),arrive.end()); 
    sort(depart.begin(),depart.end());
    int i=0,j=0,count=0;
    while(i<depart.size() && j<arrive.size()) {
        if(arrive[i]<depart[j]) {
            count++;
            i++;
            if(count>K)
                return false;
        }
        else {
                j++;
                count--;
        }
        
    }
    return true;
    
}
