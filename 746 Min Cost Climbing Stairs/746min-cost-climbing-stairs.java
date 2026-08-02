class Solution {
    // Space optimised solution
    public static int solve(int[] cost){
        int n = cost.length;
        int prev2 = cost[0];
        int prev1 = cost[1];

        for (int i = 2; i < n; i++) {
            int curr = cost[i] + Math.min(prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return Math.min(prev2, prev1);
    }

    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        // edge case
        if(n == 1){
            return 0;
        }
        // int dp[] = new int[n];
        // Arrays.fill(dp,-1);
        // int ans = Math.min(solveMem(cost, n-1,dp), solveMem(cost, n-2,dp));
        // return solveTab(cost);
        return solve(cost);
    }
}