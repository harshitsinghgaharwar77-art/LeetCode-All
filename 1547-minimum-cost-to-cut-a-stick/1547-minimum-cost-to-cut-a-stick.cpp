class Solution {
private:
    // top-down approach
    int solveMem(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int mini = INT_MAX;

        for (int idx = i; idx <= j; idx++) {
            int cost = cuts[j + 1] - cuts[i - 1] +
                       solveMem(i, idx - 1, cuts, dp) +
                       solveMem(idx + 1, j, cuts, dp);

            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }

    // tabulation
    int solveTab(int n, vector<int>& cuts) {
        int s = cuts.size();

        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(s + 2, vector<int>(s + 2, 0));

        for (int i = s; i >= 1; i--) {
            for (int j = i; j <= s; j++) {

                int mini = INT_MAX;

                for (int idx = i; idx <= j; idx++) {
                    int cost = cuts[j + 1] - cuts[i - 1]
                             + dp[i][idx - 1]
                             + dp[idx + 1][j];

                    mini = min(mini, cost);
                }

                dp[i][j] = mini;
            }
        }

        return dp[1][s];
    }

public:
    int minCost(int n, vector<int>& cuts) {
        return solveTab(n, cuts);
    }
};