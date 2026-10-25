
class Solution {
    int solve(int n, int idx){
        if(n == 0) return 0;
        if(n < 0 || idx * idx > n) return 1e9;
        // include current square
        int incl = 1 + solve(n - idx * idx, idx);
        // exclude current square
        int excl = solve(n, idx + 1);
        return min(incl, excl);
    }

    int solveMem(int n, int idx, vector<vector<int>> &dp){
        if(n == 0) return 0;
        if(n < 0 || idx * idx > n) return 1e9;
        if(dp[n][idx] != -1) return dp[n][idx];
        // include current square
        int incl = 1 + solveMem(n - idx * idx, idx,dp);
        // exclude current square
        int excl = solveMem(n, idx + 1,dp);
        return dp[n][idx] = min(incl, excl);
    }

    int solveTab(int n){
        vector<vector<int>> dp(n+1, vector<int>(n+2, 1e9));
        for(int idx = 1; idx <= n+1; idx++){
            dp[0][idx] = 0;
        }
        for(int x = 1; x <= n; x++){
            for(int idx = x; idx >= 1; idx--){
                // include current square
                int incl = 1e9;
                if(idx * idx <= x){
                    incl = 1 + dp[x - idx*idx][idx];
                }
                // exclude current square
                int excl = dp[x][idx+1];
                dp[x][idx] = min(incl, excl);
            }
        }
        return dp[n][1];
    }

    int solveFinal(int n){
        vector<int> dp(n+1,1e9);
        dp[0] = 0;
        for(int idx = 1; idx*idx<=n; idx++){
            int sq = idx*idx;
            for(int j = sq; j <= n; j++){
                dp[j] = min(dp[j], 1+dp[j-sq]);
            }
        }
        return dp[n];
    }
public:
    int numSquares(int n) {
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solveFinal(n);
    }
};
