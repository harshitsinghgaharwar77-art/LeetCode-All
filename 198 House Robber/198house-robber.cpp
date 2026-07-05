class Solution {
private:
    int solve(vector<int>& nums, int idx, vector<int>& dp) {
        // base case
        if (idx >= nums.size()) {
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        int incl = nums[idx] + solve(nums, idx + 2, dp);
        int excl = 0 + solve(nums, idx + 1, dp);
        int finalAns = max(incl, excl);
        dp[idx] = finalAns;
        return dp[idx];
    }

public:
    int rob(vector<int>& nums) {
        int idx = 0;
        int n = nums.size();
        vector<int> dp(n,-1);
        int ans = solve(nums, idx,dp);
        return ans;
    }
};