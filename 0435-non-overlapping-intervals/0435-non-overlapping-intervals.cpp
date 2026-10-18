class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        // sort the array according to second element
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        int cnt = 0;
        int endInterval = intervals[0][1];
        for(int i = 1; i < n; i++){
            // overlapping interval found
            if(intervals[i][0] < endInterval) cnt++;
            // update the end number
            else endInterval = intervals[i][1];
        }
        return cnt;
    }
};