class Solution {
private:
    // Top-down / Memoization
    int solveMem(int idx, int diff, vector<int>& nums,
                 vector<unordered_map<int, int>>& dp) {

        // Base case
        if (idx < 0) {
            return 0;
        }

        // Already calculated
        if (dp[idx].count(diff)) {
            return dp[idx][diff];
        }

        int ans = 0;

        // Check previous elements
        for (int j = idx - 1; j >= 0; j--) {

            if (nums[idx] - nums[j] == diff) {
                ans = max(ans, 1 + solveMem(j, diff, nums, dp));
            }
        }

        return dp[idx][diff] = ans;
    }

public:
    int longestArithSeqLength(vector<int>& nums) {

        int n = nums.size();

        if (n <= 2) {
            return n;
        }

        // Tabulation method
        int ans = 2;

        // dp[i][diff] = length of longest arithmetic
        // subsequence ending at index i with difference diff
        vector<unordered_map<int, int>> dp(n);

        for (int i = 1; i < n; i++) {

            for (int j = 0; j < i; j++) {

                int diff = nums[i] - nums[j];

                // At minimum, nums[j] itself is present
                int cnt = 1;

                if (dp[j].count(diff)) {
                    cnt = dp[j][diff];
                }

                dp[i][diff] = 1 + cnt;

                ans = max(ans, dp[i][diff]);
            }
        }

        return ans;
    }
};