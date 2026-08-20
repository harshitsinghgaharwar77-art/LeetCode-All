class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int realSum = 0;
        int expectedSum = n * (n + 1) / 2;
        for (int i = 0; i < n; i++) {
            realSum += nums[i];
        }
        return expectedSum - realSum;
    }
};