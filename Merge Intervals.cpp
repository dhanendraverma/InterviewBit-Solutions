/****************************************************************************************************************************************
push the given new interval in the intervals vecotr. Now sort all the elements of the vector by first elements, this will make he work 
easy as now the elements are sorted by first elements just check for end. Now if any interval at index (i-1) has ending which is greater
than or equal to the starting of the elements at location i, this indicates that interval at index i is getting started before the 
interval at index (i-1) was ended.If such case is there just merge this two intervals means extend the interval of the location (i-1)
to the maximum of the ending of both(i-1 and i). If no such case is there means there is no any overlapping and we need to push this 
new interval.
*****************************************************************************************************************************************/


bool comp(Interval a, Interval b) {
    return a.start<b.start;
}
 
 
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    intervals.push_back(newInterval);
    sort(intervals.begin(),intervals.end(),comp);
    vector<Interval> ans;
    int n=intervals.size();
    ans.push_back(intervals[0]);
    for(int i=1;i<n;i++){
        if(intervals[i].start<=ans.back().end)
         ans.back().end=max(ans.back().end, intervals[i].end);
        else
         ans.push_back(intervals[i]);
    }
    return ans;
    
}
