class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int diff[1001] = {0};
        for(auto &t : trips){
            int cnt = t[0];
            int start = t[1];
            int end = t[2];
            diff[start] += cnt;
            diff[end] -= cnt;
        }
        int cumSum = 0;
        for(int i = 0; i <= 1000; i++){
            cumSum += diff[i];
            if(cumSum > capacity) return false;
        }
        return true;
    }
};