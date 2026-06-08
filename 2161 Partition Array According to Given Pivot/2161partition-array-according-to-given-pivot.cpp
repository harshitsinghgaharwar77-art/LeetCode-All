class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> temp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) {
                temp.push_back(nums[i]); // smaller sorted
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] == pivot) {
                temp.push_back(nums[i]); // equals sorted
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > pivot) {
                temp.push_back(nums[i]); // larger sorted
            }
        }
        return temp;
    }
};