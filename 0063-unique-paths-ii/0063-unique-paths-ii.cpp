class Solution {
    // top-down approach
    int solveMem(int i, int j, vector<vector<int>>& grid,
                 vector<vector<int>>& dp) {

        // obstacle
        if (i >= 0 && j >= 0 && grid[i][j] == 1)
            return 0;

        // base case
        if (i == 0 && j == 0)
            return 1;

        // out of bounds
        if (i < 0 || j < 0)
            return 0;

        // already calculated
        if (dp[i][j] != -1)
            return dp[i][j];

        int up = solveMem(i - 1, j, grid, dp);
        int left = solveMem(i, j - 1, grid, dp);

        return dp[i][j] = up + left;
    }

    // tabulation method
    int solveTab(vector<vector<int>>& mat){
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 1) dp[i][j] = 0;
                else if(i == 0 && j == 0) dp[i][j] = 1;
                else{
                    int up = 0, left = 0;
                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];
                    dp[i][j] = (up+left);
                }
            }
        }
        return dp[n-1][m-1];
    }

    // space optimised solution
    int solve(vector<vector<int>>& mat){
        int n = mat.size();
        int m = mat[0].size();
        vector<int> prev(m,0), curr(m,0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 1) curr[j] = 0;
                else if(i == 0 && j == 0) curr[j] = 1;
                else{
                    int up = 0, left = 0;
                    if(i > 0) up = prev[j];
                    if(j > 0) left = curr[j-1];
                    curr[j] = (up+left);
                }
            }
            prev = curr;
        }
        return prev[m-1];
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // int n = obstacleGrid.size();
        // int m = obstacleGrid[0].size();

        // vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(obstacleGrid);
    }
};