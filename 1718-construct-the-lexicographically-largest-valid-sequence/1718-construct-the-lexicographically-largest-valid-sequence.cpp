
class Solution {
public:
    bool solve(int idx, vector<int>& ans, vector<bool>& used, int n) {
        // All positions are filled
        if (idx == ans.size()) return true;

        // Skip already filled positions
        if (ans[idx] != 0) {
            return solve(idx + 1, ans, used, n);
        }

        // Try numbers in descending order
        for (int num = n; num >= 1; num--) {

            if (used[num]) continue;

            // Number 1 occurs only once
            if (num == 1) {
                ans[idx] = 1;
                used[num] = true;

                if (solve(idx + 1, ans, used, n))
                    return true;

                ans[idx] = 0;
                used[num] = false;
            }

            // Numbers 2 to n occur twice
            else {
                int j = idx + num;

                if (j < ans.size() && ans[j] == 0) {
                    ans[idx] = num;
                    ans[j] = num;
                    used[num] = true;

                    if (solve(idx + 1, ans, used, n))
                        return true;

                    ans[idx] = 0;
                    ans[j] = 0;
                    used[num] = false;
                }
            }
        }

        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2 * n - 1, 0);
        vector<bool> used(n + 1, false);

        solve(0, ans, used, n);

        return ans;
    }
};
