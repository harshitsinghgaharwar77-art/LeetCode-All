class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;

        long long dp = 1;  // empty subsequence

        vector<long long> last(26, 0);

        for (char c : s) {
            int idx = c - 'a';

            long long oldDp = dp;

            // Add current character to every existing subsequence
            dp = (2 * dp) % MOD;

            // Remove duplicates caused by previous occurrence
            dp = (dp - last[idx] + MOD) % MOD;

            // Store dp before processing current character
            last[idx] = oldDp;
        }

        // Remove empty subsequence
        return (dp - 1 + MOD) % MOD;
    }
};