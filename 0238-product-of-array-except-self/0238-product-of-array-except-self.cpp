class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        long long prod = 1;
        int zeroCount = 0;

        for (int num : nums) {
            if (num == 0) {
                zeroCount++;
            } else {
                prod *= num;
            }
        }

        if (zeroCount > 1) {
            return vector<int>(n, 0);
        }

        for (int i = 0; i < n; i++) {
            if (zeroCount == 1) {
                ans[i] = (nums[i] == 0) ? prod : 0;
            } else {
                ans[i] = prod / nums[i];
            }
        }

        return ans;
    }
};