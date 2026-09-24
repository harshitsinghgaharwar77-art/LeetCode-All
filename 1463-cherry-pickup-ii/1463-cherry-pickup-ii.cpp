class Solution {
    // top-down approach
    int solveMem(int i, int j1, int j2, int r, int c,
                 vector<vector<int>>& grid,
                 vector<vector<vector<int>>> &dp) {

        // base case
        if (j1 < 0 || j2 < 0 || j1 >= c || j2 >= c) {
            return -1e8;
        }

        if (i == r - 1) {
            if (j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }

        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        // explore all paths
        int maxi = -1e8;

        for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {

                int value = 0;

                if (j1 == j2)
                    value = grid[i][j1];
                else
                    value = grid[i][j1] + grid[i][j2];

                value += solveMem(i + 1, j1 + dj1, j2 + dj2,
                                  r, c, grid, dp);

                maxi = max(maxi, value);
            }
        }

        return dp[i][j1][j2] = maxi;
    }

    // tabulation method
    int solveTab(vector<vector<int>>& grid) {

        int r = grid.size();
        int c = grid[0].size();

        vector<vector<vector<int>>> dp(
            r, vector<vector<int>>(c, vector<int>(c, 0))
        );

        // base case
        for (int j1 = 0; j1 < c; j1++) {
            for (int j2 = 0; j2 < c; j2++) {

                if (j1 == j2)
                    dp[r - 1][j1][j2] = grid[r - 1][j1];
                else
                    dp[r - 1][j1][j2] =
                        grid[r - 1][j1] + grid[r - 1][j2];
            }
        }

        // bottom-up
        for (int i = r - 2; i >= 0; i--) {

            for (int j1 = 0; j1 < c; j1++) {

                for (int j2 = 0; j2 < c; j2++) {

                    int maxi = -1e8;

                    for (int dj1 = -1; dj1 <= 1; dj1++) {

                        for (int dj2 = -1; dj2 <= 1; dj2++) {

                            int value = 0;

                            if (j1 == j2)
                                value = grid[i][j1];
                            else
                                value = grid[i][j1] + grid[i][j2];

                            // check boundary
                            if (j1 + dj1 >= 0 && j1 + dj1 < c &&
                                j2 + dj2 >= 0 && j2 + dj2 < c) {

                                value += dp[i + 1][j1 + dj1][j2 + dj2];

                                maxi = max(maxi, value);
                            }
                        }
                    }

                    dp[i][j1][j2] = maxi;
                }
            }
        }

        return dp[0][0][c - 1];
    }

    // space optimisation
    int solve(vector<vector<int>>& grid) {

        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> front(c,vector<int>(c,0));
        vector<vector<int>> curr(c,vector<int>(c,0));
        // base case
        for (int j1 = 0; j1 < c; j1++) {
            for (int j2 = 0; j2 < c; j2++) {

                if (j1 == j2)
                    front[j1][j2] = grid[r - 1][j1];
                else
                    front[j1][j2] =
                        grid[r - 1][j1] + grid[r - 1][j2];
            }
        }

        // bottom-up
        for (int i = r - 2; i >= 0; i--) {

            for (int j1 = 0; j1 < c; j1++) {

                for (int j2 = 0; j2 < c; j2++) {

                    int maxi = -1e8;

                    for (int dj1 = -1; dj1 <= 1; dj1++) {

                        for (int dj2 = -1; dj2 <= 1; dj2++) {

                            int value = 0;

                            if (j1 == j2)
                                value = grid[i][j1];
                            else
                                value = grid[i][j1] + grid[i][j2];

                            // check boundary
                            if (j1 + dj1 >= 0 && j1 + dj1 < c &&
                                j2 + dj2 >= 0 && j2 + dj2 < c) {

                                value += front[j1 + dj1][j2 + dj2];

                                maxi = max(maxi, value);
                            }
                        }
                    }

                    curr[j1][j2] = maxi;
                }
            }
            front = curr;
        }

        return front[0][c - 1];
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        return solve(grid);
    }
};