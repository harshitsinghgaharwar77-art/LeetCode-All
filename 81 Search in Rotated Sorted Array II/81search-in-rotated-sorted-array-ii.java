class Solution {

    public boolean search(int[] nums, int target) {

        int s = 0;
        int e = nums.length - 1;

        while (s <= e) {

            int mid = s + (e - s) / 2;

            // Target found
            if (nums[mid] == target) {
                return true;
            }

            // Duplicates: cannot determine which side is sorted
            if (nums[s] == nums[mid] && nums[mid] == nums[e]) {
                s++;
                e--;
            }

            // Left half is sorted
            else if (nums[s] <= nums[mid]) {

                if (nums[s] <= target && target < nums[mid]) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            }

            // Right half is sorted
            else {

                if (nums[mid] < target && target <= nums[e]) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
        }

        return false;
    }
}