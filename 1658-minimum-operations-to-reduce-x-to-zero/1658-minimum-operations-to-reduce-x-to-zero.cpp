class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        long long totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        long long target = totalSum - x;

        // If target < 0, even removing the whole array is not enough
        if (target < 0) {
            return -1;
        }

        // target == 0 means remove the entire array
        if (target == 0) {
            return n;
        }

        int left = 0;
        long long sum = 0;
        int maxLen = -1;

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            // Shrink the window if sum becomes too large
            while (left <= right && sum > target) {
                sum -= nums[left];
                left++;
            }

            // Found a subarray with sum = target
            if (sum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        if (maxLen == -1) {
            return -1;
        }

        return n - maxLen;
    }
};