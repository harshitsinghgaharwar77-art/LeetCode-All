class Solution {
private:
    // Recursive solution
    int solveRec(int idx, int buy, vector<int>& prices) {
        if (idx == prices.size()) {
            return 0;
        }
        int profit = 0;
        if (buy) {
            int buyKaro = (-prices[idx] + solveRec(idx + 1, 0, prices));
            int ignoreKaro = (0 + solveRec(idx + 1, 1, prices));
            profit = max(buyKaro, ignoreKaro);
        } else {
            int sellKaro = (prices[idx] + solveRec(idx + 1, 1, prices));
            int ignooreKaro = (0 + solveRec(idx + 1, 0, prices));
            profit = max(sellKaro, ignooreKaro);
        }
        return profit;
    }

    // Top down solution
    int solveMem(int idx, int buy, vector<int>& prices,
                 vector<vector<int>>& dp) {
        if (idx == prices.size()) {
            return 0;
        }
        if (dp[idx][buy] != -1) {
            return dp[idx][buy];
        }
        int profit = 0;
        if (buy) {
            int buyKaro = (-prices[idx] + solveMem(idx + 1, 0, prices, dp));
            int ignoreKaro = (0 + solveMem(idx + 1, 1, prices, dp));
            profit = max(buyKaro, ignoreKaro);
        } else {
            int sellKaro = (prices[idx] + solveMem(idx + 1, 1, prices, dp));
            int ignooreKaro = (0 + solveMem(idx + 1, 0, prices, dp));
            profit = max(sellKaro, ignooreKaro);
        }
        return dp[idx][buy] = profit;
    }

    // Tabulation method
    int solveTab(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if(buy){
                    int buyKaro = (-prices[idx] + dp[idx + 1][0]);
                    int ignoreKaro = (0 + dp[idx + 1][1]);
                    profit = max(buyKaro, ignoreKaro);
                }else{
                    int sellKaro = (prices[idx] + dp[idx + 1][1]);
                    int ignooreKaro = (0 + dp[idx + 1][0]);
                    profit = max(sellKaro, ignooreKaro);
                }
                dp[idx][buy] = profit;
            }
        }
        return dp[0][1];
    }

    // space optimised solution
    int solve(vector<int>& prices) {
        int n = prices.size();
        vector<int> curr(2,0);
        vector<int> next(2,0);
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if(buy){
                    int buyKaro = (-prices[idx] + next[0]);
                    int ignoreKaro = (0 + next[1]);
                    profit = max(buyKaro, ignoreKaro);
                }else{
                    int sellKaro = (prices[idx] + next[1]);
                    int ignooreKaro = (0 + next[0]);
                    profit = max(sellKaro, ignooreKaro);
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return next[1];
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        int ans = solve(prices);
        return ans;
    }
};