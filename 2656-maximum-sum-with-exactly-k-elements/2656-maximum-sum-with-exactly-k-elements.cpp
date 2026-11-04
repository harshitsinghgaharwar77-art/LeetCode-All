class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(), nums.end());
        return k * maxi + (k * (k - 1)) / 2;
    }
};