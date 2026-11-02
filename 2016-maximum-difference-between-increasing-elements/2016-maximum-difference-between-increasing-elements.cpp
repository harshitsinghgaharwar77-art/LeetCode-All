class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size(), mini = nums[0], ans = -1;
        for(int i = 1; i < n; i++){
            if(nums[i] > mini) ans = max(ans, nums[i]-mini);
            mini = min(mini, nums[i]);
        }
        return ans;
    }
};
