class Solution {
private:
    // Recursive solution
    int solveRec(string& a, string& b, int i, int j) {
        // base case
        if (i == a.length())
            return b.length() - j;

        if (j == b.length())
            return a.length() - i;

        int ans = 0;

        if (a[i] == b[j]) {
            return solveRec(a, b, i + 1, j + 1);
        } 
        else {
            int insertAns = 1 + solveRec(a, b, i, j + 1);      // insert
            int deleteAns = 1 + solveRec(a, b, i + 1, j);      // delete
            int replaceAns = 1 + solveRec(a, b, i + 1, j + 1); // replace

            ans = min(insertAns, min(deleteAns, replaceAns));
        }

        return ans;
    }


    // Top down approach
    int solveMem(string& a, string& b, int i, int j,
                 vector<vector<int>>& dp) {

        // base case
        if (i == a.length())
            return b.length() - j;

        if (j == b.length())
            return a.length() - i;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;

        if (a[i] == b[j]) {
            return dp[i][j] = solveMem(a, b, i + 1, j + 1, dp);
        } 
        else {
            int insertAns = 1 + solveMem(a, b, i, j + 1, dp);      // insert
            int deleteAns = 1 + solveMem(a, b, i + 1, j, dp);      // delete
            int replaceAns = 1 + solveMem(a, b, i + 1, j + 1, dp); // replace

            ans = min(insertAns, min(deleteAns, replaceAns));
        }

        return dp[i][j] = ans;
    }


    int solveTab(string a, string b) {

        int n = a.length();
        int m = b.length();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base cases
        for (int j = 0; j <= m; j++) {
            dp[n][j] = m - j;
        }

        for (int i = 0; i <= n; i++) {
            dp[i][m] = n - i;
        }

        // Fill table
        for (int i = n - 1; i >= 0; i--) {

            for (int j = m - 1; j >= 0; j--) {

                int ans = 0;

                if (a[i] == b[j]) {

                    // FIX: don't return here
                    dp[i][j] = dp[i + 1][j + 1];

                } 
                else {

                    int insertAns = 1 + dp[i][j + 1];       // insert
                    int deleteAns = 1 + dp[i + 1][j];       // delete
                    int replaceAns = 1 + dp[i + 1][j + 1];  // replace

                    ans = min(insertAns, min(deleteAns, replaceAns));

                    dp[i][j] = ans;
                }
            }
        }

        return dp[0][0];
    }


public:
    int minDistance(string word1, string word2) {

        // int n = word1.length();
        // int m = word2.length();
        // vector<vector<int>> dp(n, vector<int>(m, -1));

        int ans = solveTab(word1, word2);

        return ans;
    }
};