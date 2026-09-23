class Solution {
private:
    // top-down approach
    long long solveMem(int i, int j, string& s, string& t, vector<vector<long long>>& dp) {
        if (j < 0)
            return 1;

        if (i < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == t[j])
            return dp[i][j] = solveMem(i - 1, j - 1, s, t, dp) +
                              solveMem(i - 1, j, s, t, dp);

        return dp[i][j] = solveMem(i - 1, j, s, t, dp);
    }

    // Tabulation
    int solveTab(string& s, string& t) {
        int n = s.size();
        int m = t.size();

        // Use unsigned long long to prevent signed integer overflow
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(m + 1, 0));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return (int)dp[n][m];
    }

    // Space optimized
    int solve(string& s, string& t) {
        int n = s.size();
        int m = t.size();

        // Use unsigned long long to prevent signed integer overflow
        vector<unsigned long long> dp(m + 1, 0);

        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] = dp[j - 1] + dp[j];
                }
            }
        }
        return (int)dp[m];
    }

public:
    int numDistinct(string s, string t) {
        return solve(s, t);
    }
};