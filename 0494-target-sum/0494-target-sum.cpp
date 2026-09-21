class Solution {
private:
    int solveRec(vector<int>& nums, int target, int sum, int idx){
        // base case
        if(idx == nums.size()){
            if(sum == target) return 1;
            else return 0;
        }
        int plus = solveRec(nums, target, sum + nums[idx], idx + 1);
        int minus = solveRec(nums, target, sum - nums[idx], idx + 1);
        return plus + minus;
    }

    int solveMem(vector<int>& nums, int target, int sum, int idx, vector<vector<int>> &dp){
         // base case
        if(idx == nums.size()){
            if(sum == target) return 1;
            else return 0;
        }
        if(dp[sum][idx] != -1) return dp[sum][idx];
        int plus = solveMem(nums, target, sum + nums[idx], idx + 1,dp);
        int minus = solveMem(nums, target, sum - nums[idx], idx + 1,dp);
        return dp[sum][idx] = plus + minus;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solveRec(nums, target, 0, 0);
    }
};