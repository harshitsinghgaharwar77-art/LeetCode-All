class Solution {
    // top-down approach
    int solveMem(int i, int j, vector<vector<int>>& matrix,
                 vector<vector<int>>& dp) {

        // out of bounds
        if (j < 0 || j >= matrix[0].size())
            return 1e9;

        // base case
        if (i == 0)
            return matrix[i][j];

        // already calculated
        if (dp[i][j] != -100000)
            return dp[i][j];

        int up = matrix[i][j] + solveMem(i - 1, j, matrix, dp);
        int ld = matrix[i][j] + solveMem(i - 1, j - 1, matrix, dp);
        int rd = matrix[i][j] + solveMem(i - 1, j + 1, matrix, dp);

        return dp[i][j] = min(up, min(ld, rd));
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        // Initialize with -100000 to avoid conflicts with negative path sums
        vector<vector<int>> dp(n, vector<int>(m, -100000));

        int mini = 1e9;

        // Path can end at any column in the last row
        for (int j = 0; j < m; j++) {
            mini = min(mini, solveMem(n - 1, j, matrix, dp));
        }

        return mini;
    }
};