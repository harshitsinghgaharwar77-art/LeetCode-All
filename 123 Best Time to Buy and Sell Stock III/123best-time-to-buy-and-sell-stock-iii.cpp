class Solution {
private:
    // Recursive solution
    int solveRec(int idx, int buy, vector<int>& prices, int limit) {
        // Base case
        if (idx == prices.size() || limit == 0) {
            return 0;
        }
        int profit = 0;
        if (buy) {
            int buyKaro = -prices[idx] + solveRec(idx + 1, 0, prices, limit);
            int ignoreKaro = solveRec(idx + 1, 1, prices, limit);
            profit = max(buyKaro, ignoreKaro);
        } else {
            int sellKaro =
                prices[idx] + solveRec(idx + 1, 1, prices, limit - 1);
            int ignoreKaro = solveRec(idx + 1, 0, prices, limit);
            profit = max(sellKaro, ignoreKaro);
        }
        return profit;
    }

    // Top Down / Memoization
    int solveMem(int idx, int buy, vector<int>& prices, int limit,
                 vector<vector<vector<int>>>& dp) {
        // Base case
        if (idx == prices.size() || limit == 0) {
            return 0;
        }
        // Already calculated
        if (dp[idx][buy][limit] != -1) {
            return dp[idx][buy][limit];
        }
        int profit = 0;
        if (buy) {
            int buyKaro =
                -prices[idx] + solveMem(idx + 1, 0, prices, limit, dp);
            int ignoreKaro = solveMem(idx + 1, 1, prices, limit, dp);
            profit = max(buyKaro, ignoreKaro);
        } else {
            int sellKaro =
                prices[idx] + solveMem(idx + 1, 1, prices, limit - 1, dp);
            int ignoreKaro = solveMem(idx + 1, 0, prices, limit, dp);
            profit = max(sellKaro, ignoreKaro);
        }
        return dp[idx][buy][limit] = profit;
    }

    // Tabulation method
    int solveTab(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int limit = 1; limit <= 2; limit++) {
                    int profit = 0;
                    if (buy) {
                        int buyKaro = -prices[idx] + dp[idx + 1][0][limit];
                        int ignoreKaro = dp[idx + 1][1][limit];
                        profit = max(buyKaro, ignoreKaro);
                    } else {
                        int sellKaro = prices[idx] + dp[idx + 1][1][limit-1];
                        int ignoreKaro = dp[idx + 1][0][limit];
                        profit = max(sellKaro, ignoreKaro);
                    }
                    dp[idx][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][2];
    }

    // Space optimisation
    int solve(vector<int>& prices){
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(3,0));
        vector<vector<int>> next(2, vector<int>(3,0));
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int limit = 1; limit <= 2; limit++) {
                    int profit = 0;
                    if (buy) {
                        int buyKaro = -prices[idx] + next[0][limit];
                        int ignoreKaro = next[1][limit];
                        profit = max(buyKaro, ignoreKaro);
                    } else {
                        int sellKaro = prices[idx] + next[1][limit-1];
                        int ignoreKaro = next[0][limit];
                        profit = max(sellKaro, ignoreKaro);
                    }
                    curr[buy][limit] = profit;
                }
            }
            next = curr;
        }
        return next[1][2];
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // dp[idx][buy][limit]
        // vector<vector<vector<int>>> dp(
            // n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(prices);
    }
};