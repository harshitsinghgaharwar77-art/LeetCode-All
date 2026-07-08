class Solution {

    static boolean solve(int[] nums, int idx, int[] dp) {
        // Base cases
        if (idx == nums.length - 1)
            return true;

        if (idx >= nums.length)
            return false;

        if (nums[idx] == 0)
            return false;

        // DP check
        if (dp[idx] != -1)
            return dp[idx] == 1;

        int maxJumps = nums[idx];

        for (int jump = 1; jump <= maxJumps; jump++) {
            if (solve(nums, idx + jump, dp)) {
                dp[idx] = 1;
                return true;
            }
        }

        dp[idx] = 0;
        return false;
    }

    public boolean canJump(int[] nums) {
        int[] dp = new int[nums.length];
        java.util.Arrays.fill(dp, -1); // -1 = not computed

        return solve(nums, 0, dp);
    }
}