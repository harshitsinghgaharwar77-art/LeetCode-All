class Solution {
private:
    // Recursive solution
    int solveRec(vector<int>& satisfaction, int idx, int time) {
        // base case
        if (idx == satisfaction.size()) {
            return 0;
        }
        int incl = satisfaction[idx] * (time + 1) +
                   solveRec(satisfaction, idx + 1, time + 1);
        int excl = 0 + solveRec(satisfaction, idx + 1, time);

        return max(incl, excl);
    }

    // Top down approach
    int solveMem(vector<int>& satisfaction, int idx, int time,
                 vector<vector<int>>& dp) {
        // base case
        if (idx == satisfaction.size()) {
            return 0;
        }
        if (dp[idx][time] != -1) {
            return dp[idx][time];
        }
        int incl = satisfaction[idx] * (time + 1) +
                   solveMem(satisfaction, idx + 1, time + 1, dp);
        int excl = 0 + solveMem(satisfaction, idx + 1, time, dp);

        return dp[idx][time] = max(incl, excl);
    }

    // Tabulation method
    int solveTab(vector<int>& satisfaction) {
        int n = satisfaction.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int time = idx; time >= 0; time--) {
                int incl =
                    satisfaction[idx] * (time + 1) + dp[idx + 1][time + 1];
                int excl = 0 + dp[idx + 1][time];

                dp[idx][time] = max(incl, excl);
            }
        }
        return dp[0][0];
    }

    // Space optimised solution
    int solve(vector<int>& satisfaction) {
        int n = satisfaction.size();

        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int time = idx; time >= 0; time--) {
                int incl = satisfaction[idx] * (time + 1) + next[time + 1];
                int excl = 0 + next[time];

                curr[time] = max(incl, excl);
            }
            next = curr;
        }
        return next[0];
    }

    int solveMoreOptimised(vector<int>& satisfaction) {
        int suffixSum = 0;
        int ans = 0;
        for (int i = satisfaction.size() - 1; i >= 0; i--) {
            suffixSum += satisfaction[i];
            if (suffixSum <= 0)
                break;
            ans += suffixSum;
        }
        return ans;
    }

public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        // return solveRec(satisfaction, 0, 0);

        // int n = satisfaction.size();
        // vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        // return solveMem(satisfaction, 0, 0, dp);

        // return solveTab(satisfaction);
        //return solve(satisfaction);
        return solveMoreOptimised(satisfaction);
    }
};