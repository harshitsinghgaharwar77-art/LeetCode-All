class Solution {
private:
    int getPivot(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = n - 1;
        while (s < e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] > nums[e]) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        return s;
    }

public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int pivotIdx = getPivot(nums);
        return nums[pivotIdx];
    }
};