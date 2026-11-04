class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0, leftSum = 0;
        for(int &num : nums) totalSum += num;
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            int rightSum = totalSum - leftSum - nums[i];
            ans[i] = abs(leftSum - rightSum);
            leftSum += nums[i];
        }
        return ans;
    }
};