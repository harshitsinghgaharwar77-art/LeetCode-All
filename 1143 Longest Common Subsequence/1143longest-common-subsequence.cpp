class Solution {
    // Recursive solution
    int solveRec(string &a, string &b, int i, int j) {
        if (i == a.length()) return 0;
        if (j == b.length()) return 0;

        int ans = 0;

        if (a[i] == b[j]) {
            ans = 1 + solveRec(a, b, i + 1, j + 1);
        }
        else {
            ans = max(
                solveRec(a, b, i + 1, j),
                solveRec(a, b, i, j + 1)
            );
        }

        return ans;
    }

    // Top-down / Memoization
    int solveMem(string &a, string &b, int i, int j,
                 vector<vector<int>> &dp) {

        if (i == a.length()) return 0;
        if (j == b.length()) return 0;

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = 0;

        if (a[i] == b[j]) {
            ans = 1 + solveMem(a, b, i + 1, j + 1, dp);
        }
        else {
            ans = max(
                solveMem(a, b, i + 1, j, dp),
                solveMem(a, b, i, j + 1, dp)
            );
        }

        return dp[i][j] = ans;
    }

    // Tabulation
    int solveTab(string a, string b) {
        int n = a.length();
        int m = b.length();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {

                if (a[i] == b[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else {
                    dp[i][j] = max(
                        dp[i + 1][j],
                        dp[i][j + 1]
                    );
                }
            }
        }

        return dp[0][0];
    }

    // Space optimisation
    int solve(string a, string b){
        vector<int> curr(b.length()+1,0);
        vector<int> next(b.length()+1,0);

        for(int i = a.length()-1; i >= 0; i--){
            for(int j = b.length()-1; j>=0; j--){
                int ans = 0;
                if(a[i] == b[j]){
                    ans = 1 + next[j+1];
                }else{
                    ans = max(next[j], curr[j+1]);
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        return solve(text1, text2);
    }
};