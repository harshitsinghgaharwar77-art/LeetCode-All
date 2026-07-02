class Solution {
private:
    int lowerBound(vector<int>& nums, int x) {
        int s = 0, e = nums.size() - 1;
        int ans = nums.size();

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] >= x) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }

    int upperBound(vector<int>& nums, int x) {
        int s = 0, e = nums.size() - 1;
        int ans = nums.size();

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] > x) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lowerBound(nums, target);

        if (first == nums.size() || nums[first] != target) {
            return {-1, -1};
        }

        int last = upperBound(nums, target) - 1;

        return {first, last};
    }
};