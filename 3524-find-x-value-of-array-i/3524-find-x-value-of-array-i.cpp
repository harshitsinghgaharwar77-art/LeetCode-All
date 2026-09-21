class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {

        vector<long long> ans(k, 0);

        // dp[r] = number of subarrays ending at previous index
        // whose product % k == r
        vector<long long> dp(k, 0);

        for (int num : nums) {

            int val = num % k;

            // newDp will store subarrays ending at current index
            vector<long long> newDp(k, 0);

            // Start a new subarray containing only nums[i]
            newDp[val]++;

            // Extend all previous subarrays
            for (int r = 0; r < k; r++) {
                if (dp[r] > 0) {
                    int newRem = (r * val) % k;
                    newDp[newRem] += dp[r];
                }
            }

            // Add all subarrays ending here to answer
            for (int r = 0; r < k; r++) {
                ans[r] += newDp[r];
            }

            dp = newDp;
        }

        return ans;
    }
};