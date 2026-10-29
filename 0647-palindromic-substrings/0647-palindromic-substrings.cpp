class Solution {
private:
    int dp[1001][1001];
    bool isPlaindrome(string& s, int i, int j) {
        if (i >= j)
            return true;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] != s[j])
            return dp[i][j] = false;
        return dp[i][j] = isPlaindrome(s, i + 1, j - 1);
    }

    // recursion + memoisation
    int solve(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPlaindrome(s, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
    // tabulation
    int solveTab(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j + i - 1 < n; j++) {
                int k = j + i - 1;
                if (j == k) {
                    // single element is palindrome
                    dp[j][k] = true;
                } else if (j + 1 == k) {
                    // two characters
                    dp[j][k] = (s[j] == s[k]);
                } else {
                    // length greater than 2
                    dp[j][k] = (s[j] == s[k] && dp[j + 1][k - 1]);
                }
                if (dp[j][k] == true)
                    cnt++;
            }
        }
        return cnt;
    }

    // space optimise
    int expand(string &s, int i, int j) {
        int cnt = 0;
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            cnt++;
            i--;
            j++;
        }
        return cnt;
    }
    // expand around centre
    int solveFinal(string s){
        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            // Odd length palindromes: a, aba
            cnt += expand(s, i, i);
            // Even length palindromes: aa, abba
            cnt += expand(s, i, i + 1);
        }
        return cnt;
    }

public:
    int countSubstrings(string s) { return solveTab(s); }
};