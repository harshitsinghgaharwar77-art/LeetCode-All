class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int expected = 1;
        int i = 0;

        while (expected <= n) {
            if (i < n && nums[i] == expected) {
                // Skip all duplicates
                while (i < n && nums[i] == expected) {
                    i++;
                }
                expected++;
            }
            else {
                ans.push_back(expected);
                expected++;
            }
        }

        return ans;
    }
};