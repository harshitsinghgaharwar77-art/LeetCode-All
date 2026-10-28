class Solution {
private:
    // recursive
    int solve(int i, int j, vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        if (i >= m || j >= n)
            return 1e9;
        if (i == m - 1 && j == n - 1) {
            if (dungeon[i][j] > 0)
                return 1;
            return abs(dungeon[i][j]) + 1;
        }
        int right = solve(i, j + 1, dungeon);
        int down = solve(i + 1, j, dungeon);
        int ans = min(right, down) - dungeon[i][j];
        return (ans > 0) ? ans : 1;
    }

    // memoisation
    int solveMem(int i, int j, vector<vector<int>>& dungeon, vector<vector<int>> &dp) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        if (i >= m || j >= n)
            return 1e9;
        if (i == m - 1 && j == n - 1) {
            if (dungeon[i][j] > 0)
                return 1;
            return abs(dungeon[i][j]) + 1;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        int right = solveMem(i, j + 1, dungeon, dp);
        int down = solveMem(i + 1, j, dungeon, dp);
        int ans = min(right, down) - dungeon[i][j];
        return dp[i][j] = (ans > 0) ? ans : 1;
    }

    // Tabulation
    int solveTab(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(i == m-1 && j == n-1){
                    dp[i][j] = (dungeon[i][j] > 0) ? 1 : abs(dungeon[i][j]) + 1;
                }
                else{
                    int down = (i+1 >= m) ? 1e9 : dp[i+1][j];
                    int right = (j+1 >= n) ? 1e9 : dp[i][j+1];

                    int ans = min(down, right) - dungeon[i][j];
                    dp[i][j] = (ans > 0) ? ans : 1;
                }
            }
        }
        // min health required to reach (m-1,n-1) from 0,0
        return dp[0][0];
    }

    // space optimise
    int solveFinal(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<int> dp(n, 1e9);
        // Virtual cell to the right of the destination
        dp[n-1] = 1;
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(i == m-1 && j == n-1){
                    dp[j] = (dungeon[i][j] > 0) ? 1 : abs(dungeon[i][j]) + 1;
                }
                else{
                    int right = (j+1 >= n) ? 1e9 : dp[j+1];
                    int down = dp[j];
                    int ans = min(right, down) - dungeon[i][j];
                    dp[j] = (ans > 0) ? ans : 1;
                }
            }
        }
        return dp[0];
    }

public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        // int m = dungeon.size();
        // int n = dungeon[0].size();
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        return solveFinal(dungeon);
    }
};