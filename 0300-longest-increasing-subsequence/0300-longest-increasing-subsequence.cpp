class Solution {
private:
    int solveMem(int idx, int prev, vector<int>& nums, int n,
                 vector<vector<int>>& dp) {

        if (idx == n)
            return 0;

        if (dp[idx][prev + 1] != -1)
            return dp[idx][prev + 1];

        int len = solveMem(idx + 1, prev, nums, n, dp);

        if (prev == -1 || nums[idx] > nums[prev]) {
            len = max(len, 1 + solveMem(idx + 1, idx, nums, n, dp));
        }

        return dp[idx][prev + 1] = len;
    }

    int solveTab(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int prev = idx - 1; prev >= -1; prev--) {

                int len = dp[idx + 1][prev + 1];

                if (prev == -1 || nums[idx] > nums[prev]) {
                    len = max(len, 1 + dp[idx + 1][idx + 1]);
                }

                dp[idx][prev + 1] = len;
            }
        }

        return dp[0][0];
    }

    int solveSpace(vector<int>& nums) {
        int n = nums.size();

        vector<int> next(n + 1, 0);
        vector<int> curr(n + 1, 0);

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int prev = idx - 1; prev >= -1; prev--) {

                int len = next[prev + 1];

                if (prev == -1 || nums[idx] > nums[prev]) {
                    len = max(len, 1 + next[idx + 1]);
                }

                curr[prev + 1] = len;
            }

            next = curr;
        }

        return next[0];
    }

    int printLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1);
        vector<int> hash(n);

        int maxi = 1;
        int lastIndex = 0;

        for (int i = 0; i < n; i++) {
            hash[i] = i;

            for (int prev = 0; prev < i; prev++) {
                if (nums[prev] < nums[i] &&
                    1 + dp[prev] > dp[i]) {

                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }

            if (dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;
            }
        }

        vector<int> lis;

        lis.push_back(nums[lastIndex]);

        while (hash[lastIndex] != lastIndex) {
            lastIndex = hash[lastIndex];
            lis.push_back(nums[lastIndex]);
        }

        reverse(lis.begin(), lis.end());

        for (int x : lis) {
            cout << x << " ";
        }

        return maxi;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        return printLIS(nums);
    }
};