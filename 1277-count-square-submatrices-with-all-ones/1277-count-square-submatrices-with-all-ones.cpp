
class Solution {
    private:
    // recursive
    int solve(int i, int j, vector<vector<int>>& matrix){
        // base case
        if(i < 0 || j < 0) return 0;
        if(matrix[i][j] == 0) return 0;

        int top = solve(i-1, j, matrix);
        int left = solve(i, j-1, matrix);
        int diag = solve(i-1, j-1, matrix);

        return 1 + min(top, min(left, diag));
    }

    // memoisation
    int solveMem(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> &dp){
        // base case
        if(i < 0 || j < 0) return 0;
        if(matrix[i][j] == 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int top = solveMem(i-1, j, matrix,dp);
        int left = solveMem(i, j-1, matrix,dp);
        int diag = solveMem(i-1, j-1, matrix,dp);

        return dp[i][j] = 1 + min(top, min(left, diag));
    }

    // tabulation
    int solveTab(vector<vector<int>>& matrix){
        int m=matrix.size(), n=matrix[0].size(), ans=0;

        vector<vector<int>> dp(m, vector<int>(n,0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 1){
                    if(i == 0 || j == 0){
                        dp[i][j] = 1;
                    }
                    else{
                        dp[i][j] = 1 + min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                    }
                }
                ans += dp[i][j];
            }
        }
        return ans;
    }

    // space optimised
    int solveFinal(vector<vector<int>>& matrix){
        int m=matrix.size(), n=matrix[0].size(), ans=0;

        vector<int> prev(n+1, 0);
        vector<int> curr(n+1, 0);

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(matrix[i-1][j-1] == 1){
                    curr[j] = 1 + min({prev[j],curr[j-1],prev[j-1]});
                }else curr[j] = 0;

                ans += curr[j];
            }

            prev = curr;
            fill(curr.begin(), curr.end(), 0);
        }
        return ans;
    }

public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size(), ans=0;

        vector<vector<int>> dp(m, vector<int>(n,-1));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans += solveMem(i,j,matrix,dp);
            }
        }

        return ans;
    }
};
