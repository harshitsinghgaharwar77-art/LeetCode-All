class Solution {
    // top-down approach
    int solveMem(int i, int j, vector<vector<int>>& grid,
                 vector<vector<int>>& dp) {

        if (i == 0 && j == 0)
            return grid[i][j];

        if (i < 0 || j < 0)
            return 1e9;

        if (dp[i][j] != -1)
            return dp[i][j];

        int up = grid[i][j] + solveMem(i - 1, j, grid, dp);
        int left = grid[i][j] + solveMem(i, j - 1, grid, dp);

        return dp[i][j] = min(left, up);
    }

    // tabulation method
    int solveTab(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // base case
                if (i == 0 && j == 0)
                    dp[i][j] = grid[i][j];

                else {
                    int up = grid[i][j];
                    if (i > 0)
                        up += dp[i - 1][j];
                    else
                        up += 1e9;

                    int left = grid[i][j];
                    if (j > 0)
                        left += dp[i][j - 1];
                    else
                        left += 1e9;

                    dp[i][j] = min(left, up);
                }
            }
        }

        return dp[n - 1][m - 1];
    }

    // space optimisation
    int solve(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> prev(m,0);
        for (int i = 0; i < n; i++) {
            vector<int> curr(m,0);
            for (int j = 0; j < m; j++) {
                // base case
                if (i == 0 && j == 0)
                    curr[j] = grid[i][j];

                else {
                    int up = grid[i][j];
                    if (i > 0)
                        up += prev[j];
                    else
                        up += 1e9;

                    int left = grid[i][j];
                    if (j > 0)
                        left += curr[j - 1];
                    else
                        left += 1e9;

                    curr[j] = min(left, up);
                }
            }
            prev = curr;
        }

        return prev[m - 1];
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        return solve(grid);
    }
};