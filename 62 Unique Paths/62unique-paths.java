class Solution {
    int[][] dp;

    public int solve(int i, int j, int n, int m) {
        // out of bounds
        if (i >= n || j >= m) {
            return 0;
        }

        // destination
        if (i == n - 1 && j == m - 1) {
            return 1;
        }

        // already calculated
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int down = solve(i + 1, j, n, m);
        int right = solve(i, j + 1, n, m);

        return dp[i][j] = down + right;
    }

    public int uniquePaths(int m, int n) {
        dp = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = -1;
            }
        }
        return solve(0, 0, m, n);
    }
}
