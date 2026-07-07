class Solution {
    int[][] dp;

    private int solve(int[][] mat, int target, int row, int sum) {
        // base case
        if (row == mat.length) {
            return Math.abs(target - sum);
        }

        if (dp[row][sum] != -1) {
            return dp[row][sum];
        }

        int mini = Integer.MAX_VALUE;

        for (int num : mat[row]) {
            mini = Math.min(mini,
                    solve(mat, target, row + 1, sum + num));
        }

        return dp[row][sum] = mini;
    }

    public int minimizeTheDifference(int[][] mat, int target) {
        int maxSum = 0;

        // Maximum possible sum
        for (int[] row : mat) {
            int mx = 0;
            for (int num : row) {
                mx = Math.max(mx, num);
            }
            maxSum += mx;
        }

        dp = new int[mat.length][maxSum + 1];

        for (int i = 0; i < mat.length; i++) {
            Arrays.fill(dp[i], -1);
        }

        return solve(mat, target, 0, 0);
    }
}