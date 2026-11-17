
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();

        // Part 1: Precompute cost of every substring
        vector<vector<int>> cost(n, vector<int>(n, 1e9));

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int len = j - i + 1;

                // Try every proper divisor of len
                for (int d = 1; d < len; d++) {

                    if (len % d != 0)
                        continue;

                    int changes = 0;

                    // Compare characters in the same group
                    for (int x = 0; x < len - d; x++) {

                        if (x % d == 0) {
                            // Compare symmetric positions
                            // within each group
                        }

                    }

                    // Count mismatches between symmetric
                    // characters in each group
                    for (int x = 0; x < d; x++) {
                        int left = i + x;
                        int right = j - ((len - 1 - x) % d);

                        while (left < right) {
                            if (s[left] != s[right])
                                changes++;

                            left += d;
                            right -= d;
                        }
                    }

                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }

        // Part 2: Partition DP
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1e9));

        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {

                // Last substring starts at p
                for (int p = 0; p < i; p++) {

                    // Every semi-palindrome must have length >= 2
                    if (i - p < 2)
                        continue;

                    if (dp[p][j - 1] == 1e9)
                        continue;

                    dp[i][j] = min(
                        dp[i][j],
                        dp[p][j - 1] + cost[p][i - 1]
                    );
                }
            }
        }

        return dp[n][k];
    }
};
