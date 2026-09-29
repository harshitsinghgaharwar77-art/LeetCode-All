class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Valid parentheses string must have even length
        if ((m + n - 1) % 2 != 0)
            return false;

        // dp[i][j][balance]
        vector<vector<vector<bool>>> dp(
            m, vector<vector<bool>>(n, vector<bool>(m + n, false))
        );

        // Starting cell
        int balance = (grid[0][0] == '(') ? 1 : -1;

        if (balance < 0)
            return false;

        dp[0][0][balance] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Skip starting cell
                if (i == 0 && j == 0)
                    continue;

                for (int bal = 0; bal <= m + n; bal++) {

                    int newBalance;

                    if (grid[i][j] == '(')
                        newBalance = bal + 1;
                    else
                        newBalance = bal - 1;

                    // Balance cannot become negative
                    if (newBalance < 0)
                        continue;

                    // Came from top
                    if (i > 0 && dp[i - 1][j][bal]) {
                        dp[i][j][newBalance] = true;
                    }

                    // Came from left
                    if (j > 0 && dp[i][j - 1][bal]) {
                        dp[i][j][newBalance] = true;
                    }
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};