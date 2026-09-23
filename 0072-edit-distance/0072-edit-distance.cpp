class Solution {
private:
    // recursuve solution
    int solveRec(string& a, string& b, int i, int j) {
        // base case
        if (i == a.length())
            return b.length() - j;
        if (j == b.length())
            return a.length() - i;
        int ans = 0;
        if (a[i] == b[j])
            return solveRec(a, b, i + 1, j + 1);
        else {
            // insert
            int insertAns = 1 + solveRec(a, b, i, j + 1);
            // delete
            int deleteAns = 1 + solveRec(a, b, i + 1, j);
            // update
            int updateAns = 1 + solveRec(a, b, i + 1, j + 1);
            ans = min(insertAns, min(deleteAns, updateAns));
        }
        return ans;
    }
    // top-down approach
    int solveMem(string& a, string& b, int i, int j, vector<vector<int>>& dp) {
        // base case
        if (i == a.length())
            return b.length() - j;
        if (j == b.length())
            return a.length() - i;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        if (a[i] == b[j])
            return solveMem(a, b, i + 1, j + 1, dp);
        else {
            // insert
            int insertAns = 1 + solveMem(a, b, i, j + 1, dp);
            // delete
            int deleteAns = 1 + solveMem(a, b, i + 1, j, dp);
            // update
            int updateAns = 1 + solveMem(a, b, i + 1, j + 1, dp);
            ans = min(insertAns, min(deleteAns, updateAns));
        }
        return dp[i][j] = ans;
    }
    // tabulation method
    int solveTab(string& a, string& b) {
        int n = a.length(), m = b.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // base case analysis
        for (int j = 0; j <= m; j++) {
            dp[n][j] = m - j;
        }
        for (int i = 0; i <= n; i++) {
            dp[i][m] = n - i;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (a[i] == b[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    // insert
                    int insertAns = 1 + dp[i][j + 1];

                    // delete
                    int deleteAns = 1 + dp[i + 1][j];

                    // update
                    int updateAns = 1 + dp[i + 1][j + 1];
                    dp[i][j] = min(insertAns, min(deleteAns, updateAns));
                }
            }
        }
        return dp[0][0];
    }

    // space optimisation
    int solve(string& a, string& b) {
        int n = a.length(), m = b.length();
        vector<int> curr(m+1,0), next(m+1,0);
        // base case analysis
        for (int j = 0; j <= m; j++) {
            next[j] = m - j;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                // catch here -> base case se mila
                curr[b.length()] = a.length()-i;
                if (a[i] == b[j]) {
                    curr[j] = next[j + 1];
                } else {
                    // insert
                    int insertAns = 1 + curr[j + 1];

                    // delete
                    int deleteAns = 1 + next[j];

                    // update
                    int updateAns = 1 + next[j + 1];
                    curr[j] = min(insertAns, min(deleteAns, updateAns));
                }
            }
            next = curr;
        }
        return next[0];
    }
public:
    int minDistance(string word1, string word2) {
        if(word1.length() == 0) return word2.length();
        if(word2.length() == 0) return word1.length();
        return solve(word1, word2);
    }
};