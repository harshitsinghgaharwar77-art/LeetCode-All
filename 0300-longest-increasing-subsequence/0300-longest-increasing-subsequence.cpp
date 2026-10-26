class Solution {
    private:
    int solve(vector<int>& nums, int n, int prev, int idx){
        // base case
        if(idx >= n) return 0;
        int ans = solve(nums, n, prev,idx+1);
        if(prev == -1 || nums[idx] > nums[prev]){
            ans = max(ans, 1+solve(nums,n,idx,idx+1));
        }
        return ans;
    }

    int solveMem(vector<int>& nums, int n, int prev, int idx, vector<vector<int>> &dp){
        // base case
        if(idx >= n) return 0;
        if(dp[idx][prev+1] != -1) return dp[idx][prev+1];
        int ans = solveMem(nums, n, prev,idx+1,dp);
        if(prev == -1 || nums[idx] > nums[prev]){
            ans = max(ans, 1+solveMem(nums,n,idx,idx+1,dp));
        }
        return dp[idx][prev+1] = ans;
    }

    int solveTab(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int idx = n-1; idx >= 0; idx--){
            for(int prev = idx-1; prev >= -1; prev--){
                int ans = dp[idx+1][prev+1];
                if(prev == -1 || nums[idx] > nums[prev]){
                    ans = max(ans, 1 + dp[idx+1][idx+1]);
                }
                dp[idx][prev+1] = ans;
            }
        }
        return dp[0][0];
    }

    int solveFinal(vector<int>&nums){
        int n = nums.size();
        vector<int> next(n+1, 0);
        vector<int> curr(n+1, 0);
        for(int idx = n-1; idx >= 0; idx--){
            for(int prev = idx-1; prev >= -1; prev--){
                int ans = next[prev+1];
                if(prev == -1 || nums[idx] > nums[prev]){
                    ans = max(ans, 1 + next[idx+1]);
                }
                curr[prev+1] = ans;
            }
            next = curr;
        }
        return next[0];
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = solveFinal(nums);
        return ans;
    }
};