class Solution {

    public int findPivot(int[] nums) {
        int n = nums.length;
        int s = 0, e = n - 1;
        int ans = -1;

        // Array is already sorted
        if (nums[s] <= nums[e]) {
            return -1;
        }

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] <= nums[n - 1]) {
                // mid is in the second sorted part
                e = mid - 1;
            } else {
                // mid is in the first sorted part
                ans = mid;
                s = mid + 1;
            }
        }

        return ans;
    }

    public int binarySearch(int[] nums, int target, int s, int e) {

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target) {
                return mid;
            } 
            else if (nums[mid] < target) {
                s = mid + 1;
            } 
            else {
                e = mid - 1;
            }
        }

        return -1;
    }

    public int search(int[] nums, int target) {

        int n = nums.length;

        int pivotIdx = findPivot(nums);

        // Array is already sorted
        if (pivotIdx == -1) {
            return binarySearch(nums, target, 0, n - 1);
        }

        // First part: [0 ... pivotIdx]
        if (target >= nums[0] && target <= nums[pivotIdx]) {
            return binarySearch(nums, target, 0, pivotIdx);
        }

        // Second part: [pivotIdx + 1 ... n - 1]
        if (target >= nums[pivotIdx + 1] && target <= nums[n - 1]) {
            return binarySearch(nums, target, pivotIdx + 1, n - 1);
        }

        return -1;
    }
}