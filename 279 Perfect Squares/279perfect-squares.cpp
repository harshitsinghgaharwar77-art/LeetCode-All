class Solution {
private:
    // recursive solution
    int solveRec(int n) {
        // base case
        if (n == 0)
            return 0;
        int ans = n;
        for (int i = 1; i * i <= n; i++) {
            int temp = i * i;
            ans = min(ans, 1 + solveRec(n - temp));
        }
        return ans;
    }
    // Top down approach
    int solveMem(int n, vector<int>& dp) {
        // base case
        if (n == 0)
            return 0;
        // step-3:
        if (dp[n] != -1) {
            return dp[n];
        }
        int ans = n;
        for (int i = 1; i * i <= n; i++) {
            int temp = i * i;
            ans = min(ans, 1 + solveMem(n - temp, dp));
        }
        // step-2:
        dp[n] = ans;
        return dp[n];
    }
    // Tabulation method
    int solveTab(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= n; j++) {
                int temp = j * j;
                if (i - temp >= 0)
                    dp[i] = min(dp[i], 1 + dp[i - temp]);
            }
        }
        return dp[n];
    }
    // space optimised solution not possible
public:
    int numSquares(int n) {
        return solveTab(n);
    }
};