class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum = 0, ans = 0, n = gain.size();
        for(int i = 0; i < n; i++){
            sum += gain[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};