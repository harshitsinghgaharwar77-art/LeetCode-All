class Solution {

    public static boolean solve(int[] nums, int target, int idx, int[][] dp) {
        // base cases
        if (target == 0)
            return true;

        if (target < 0)
            return false;

        if (idx >= nums.length)
            return false;

        // memoization
        if (dp[idx][target] != -1)
            return dp[idx][target] == 1;

        boolean incl = solve(nums, target - nums[idx], idx + 1, dp);
        boolean excl = solve(nums, target, idx + 1, dp);

        dp[idx][target] = (incl || excl) ? 1 : 0;

        return incl || excl;
    }

    public boolean canPartition(int[] nums) {
        int sum = 0;

        for (int num : nums) {
            sum += num;
        }

        if ((sum & 1) == 1) {
            return false;
        }

        int target = sum / 2;

        int[][] dp = new int[nums.length][target + 1];

        for (int i = 0; i < nums.length; i++) {
            Arrays.fill(dp[i], -1);
        }

        return solve(nums, target, 0, dp);
    }
}