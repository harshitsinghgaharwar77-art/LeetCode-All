class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        // perfix sum
        int n = nums.size();
        long long leftSum = 0, rightSum = 0, ans = 0,sum = 0;
        for(int num : nums) sum += num;
        for(int i = 0; i < n-1; i++){
            leftSum += nums[i];
            rightSum = sum-leftSum;
            if(leftSum >= rightSum) ans++;
        }
        return ans;
    }
};