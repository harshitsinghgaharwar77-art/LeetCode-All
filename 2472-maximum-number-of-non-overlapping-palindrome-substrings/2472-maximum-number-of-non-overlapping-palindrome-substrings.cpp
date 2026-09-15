class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();

        // dp[i] = maximum number of palindromes
        // using first i characters
        vector<int> dp(n + 1, 0);

        // palindrome[i][j] tells whether s[i...j] is palindrome
        vector<vector<bool>> palindrome(n, vector<bool>(n, false));

        // Build palindrome table
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                if(s[i] == s[j] && (j - i <= 1 || palindrome[i + 1][j - 1])) {
                    palindrome[i][j] = true;
                }
            }
        }

        // DP
        for(int j = 0; j < n; j++) {

            // Don't select a palindrome ending at j
            if(j > 0) {
                dp[j + 1] = dp[j];
            }

            // Try every possible starting position
            for(int i = 0; i <= j; i++) {

                if(j - i + 1 >= k && palindrome[i][j]) {
                    dp[j + 1] = max(dp[j + 1], dp[i] + 1);
                }
            }
        }

        return dp[n];
    }
};