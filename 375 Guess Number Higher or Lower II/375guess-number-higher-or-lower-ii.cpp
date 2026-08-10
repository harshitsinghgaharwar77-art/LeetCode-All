class Solution {
private:
    // Recursive solution
    int solveRec(int start, int end) {
        if (start >= end) {
            return 0;
        }
        int ans = INT_MAX;
        for (int i = start; i <= end; i++) {
            ans =
                min(ans, i + max(solveRec(start, i - 1), solveRec(i + 1, end)));
        }
        return ans;
    }

    // Top down approach
    int solveMem(int start, int end, vector<vector<int>>& dp) {
        if (start >= end) {
            return 0;
        }
        if (dp[start][end] != -1) {
            return dp[start][end];
        }
        int ans = INT_MAX;
        for (int i = start; i <= end; i++) {
            ans = min(ans, i + max(solveMem(start, i - 1, dp),
                                   solveMem(i + 1, end, dp)));
        }
        return dp[start][end] = ans;
    }

    // Tabulation method
    int solveTab(int n) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int start = n; start >= 1; start--) {

            // start == end is already 0
            for (int end = start + 1; end <= n; end++) {

                int ans = INT_MAX;

                for (int i = start; i <= end; i++) {

                    ans = min(ans,
                              i + max(dp[start][i - 1],
                                      dp[i + 1][end]));
                }

                dp[start][end] = ans;
            }
        }

        return dp[1][n];
    }

public:
    int getMoneyAmount(int n) {
        //vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int ans = solveTab(n);
        return ans;
    }
};