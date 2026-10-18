class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        // SLIDING WINDOW
        int n = nums.size();
        long long sum = 0, maxSum = 0;
        unordered_map<int, int> mpp; // using map for duplicacy handling
        // calculate the sum of first window
        for (int i = 0; i < k; i++) {
            sum += nums[i];
            mpp[nums[i]]++;
        }
        if (mpp.size() == k) {
            maxSum = max(sum, maxSum);
        }
        for (int i = k; i < n; i++) {
            // add new element
            sum += nums[i];
            mpp[nums[i]]++;

            // remove old number form window
            sum -= nums[i - k];
            mpp[nums[i - k]]--;

            if (mpp[nums[i - k]] == 0) {
                mpp.erase(nums[i - k]);
            }

            if (mpp.size() == k) {
                maxSum = max(sum, maxSum);
            }
        }
        return maxSum;
    }
};