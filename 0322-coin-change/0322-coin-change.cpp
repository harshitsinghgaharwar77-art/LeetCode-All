
class Solution {
    int solve(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return INT_MAX;
        int mini = INT_MAX;
        for (int coin : coins) {
            int recAns = solve(coins, amount - coin);
            if (recAns != INT_MAX) {
                int totalCoinUsed = recAns + 1;
                mini = min(mini, totalCoinUsed);
            }
        }
        return mini;
    }

    int solveMem(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0) return 0;
        if (amount < 0) return INT_MAX;
        if (dp[amount] != -1) return dp[amount];
        int mini = INT_MAX;
        for (int coin : coins) {
            int recAns = solveMem(coins, amount - coin, dp);
            if (recAns != INT_MAX) {
                int totalCoinUsed = recAns + 1;
                mini = min(mini, totalCoinUsed);
            }
        }
        return dp[amount] = mini;
    }

    int solveTab(vector<int>& coins, int amount){
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            int mini = INT_MAX;
            for (int coin : coins) {
                if(i >= coin && dp[i-coin] != INT_MAX){
                    int recAns = dp[i-coin];
                    int totalCoinUsed = recAns + 1;
                    mini = min(mini, totalCoinUsed);
                }
            }  
            dp[i] = mini; 
        }
        if (dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        // vector<int> dp(amount + 1, -1);
        int ans = solveTab(coins, amount);
        if (ans == INT_MAX) return -1;
        return ans;
    }
};
