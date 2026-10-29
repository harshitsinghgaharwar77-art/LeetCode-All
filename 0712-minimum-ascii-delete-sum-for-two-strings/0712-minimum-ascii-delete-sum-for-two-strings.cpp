class Solution {
    // recursive
    int solve(string& a, string& b, int i, int j) {
        // base case
        if (i == a.length()) {
            int sum = 0;
            for (int k = j; k < b.length(); k++) {
                sum += b[k];
            }
            return sum;
        }
        if (j == b.length()) {
            int sum = 0;
            for (int k = i; k < a.length(); k++) {
                sum += a[k];
            }
            return sum;
        }
        int ans = 0;
        if (a[i] == b[j]) {
            return solve(a, b, i + 1, j + 1);
        } else {
            // delete from a
            int delA = a[i] + solve(a, b, i + 1, j);
            // delete from b
            int delB = b[j] + solve(a, b, i, j + 1);
            ans = min(delA, delB);
        }
        return ans;
    }

    // memoisation
    int solveMem(string& a, string& b, int i, int j, vector<vector<int>>& dp) {
        // base case
        if (i == a.length()) {
            int sum = 0;
            for (int k = j; k < b.length(); k++) {
                sum += b[k];
            }
            return sum;
        }
        if (j == b.length()) {
            int sum = 0;
            for (int k = i; k < a.length(); k++) {
                sum += a[k];
            }
            return sum;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        if (a[i] == b[j]) {
            return dp[i][j] = solveMem(a, b, i + 1, j + 1, dp);
        } else {
            // delete from a
            int delA = a[i] + solveMem(a, b, i + 1, j, dp);
            // delete from b
            int delB = b[j] + solveMem(a, b, i, j + 1, dp);
            ans = min(delA, delB);
        }
        return dp[i][j] = ans;
    }

    // Tabulation
    int solveTab(string& a, string& b) {
        int m = a.length(), n = b.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // base case analysis
        for (int j = n - 1; j >= 0; j--)
            dp[m][j] = b[j] + dp[m][j + 1];
        for (int i = m - 1; i >= 0; i--)
            dp[i][n] = a[i] + dp[i + 1][n];
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int ans = 0;
                if (a[i] == b[j]) {
                    ans = dp[i + 1][j + 1];
                } else {
                    // delete from a
                    int delA = a[i] + dp[i + 1][j];
                    // delete from b
                    int delB = b[j] + dp[i][j + 1];
                    ans = min(delA, delB);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    // space optimised
    int solveFinal(string& a, string& b){
        int m = a.length(), n = b.length();
        vector<int> next(n+1, 0), curr(n+1, 0);
         // base case
        for(int j = n-1; j >= 0; j--)
            next[j] = b[j] + next[j+1];
        for(int i = m-1; i >= 0; i--){
            // main part -> base case se mila
            curr[n] = a[i] + next[n];
            for(int j = n-1; j >= 0; j--){
                if(a[i] == b[j]){
                    curr[j] = next[j+1];
                }
                else{
                    // delete from a
                    int deleteA = a[i] + next[j];
                    // delete from b
                    int deleteB = b[j] + curr[j+1];
                    curr[j] = min(deleteA, deleteB);
                }
            }
            next = curr;
        }
        return next[0];
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        // int m = s1.length(), n = s2.length();
        // vector<vector<int>> dp(m, vector<int>(n,-1));
        return solveFinal(s1, s2);
    }
};