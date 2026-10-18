class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size(), j = 0;
        vector<int> ans;

        sort(nums.begin(), nums.end());

        for (int i = 1; i <= n; i++) {
            while (j < n && nums[j] < i) {
                j++;
            }
            if (j < n && nums[j] == i) {
                j++;
            } else {
                ans.push_back(i);
            }
        }

        return ans;
    }
};