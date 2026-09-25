class Solution {
private:
    // top-down approach
    int solveMem(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int maxi = 0;

        for (int idx = i; idx <= j; idx++) {
            int cost = nums[i - 1] * nums[idx] * nums[j + 1]
                     + solveMem(i, idx - 1, nums, dp)
                     + solveMem(idx + 1, j, nums, dp);

            maxi = max(maxi, cost);
        }

        return dp[i][j] = maxi;
    }

    // tabulation
    int solveTab(vector<int>& nums) {
        int n = nums.size();

        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int i = n; i >= 1; i--) {
            for (int j = i; j <= n; j++) {
                int maxi = 0;

                for (int idx = i; idx <= j; idx++) {
                    int cost = nums[i - 1] * nums[idx] * nums[j + 1]
                             + dp[i][idx - 1]
                             + dp[idx + 1][j];

                    maxi = max(maxi, cost);
                }

                dp[i][j] = maxi;
            }
        }

        return dp[1][n];
    }

public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

        return solveMem(1, n, nums, dp);
    }
};