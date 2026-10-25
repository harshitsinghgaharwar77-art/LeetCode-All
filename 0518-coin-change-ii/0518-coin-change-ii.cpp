class Solution {
    // int solve(int amount, vector<int>& coins, int idx){
    //      if (amount == 0) return 1;
    //      if(amount < 0 || idx >= coins.size()) return 0;
    //      int incl = solve(amount-coins[idx], coins, idx);
    //      int excl = solve(amount, coins, idx+1);
    //      return incl + excl;
    // }
    // int solveMem(int amount, vector<int>& coins, int idx, vector<vector<int>> &dp){
    //      if (amount == 0) return 1;
    //      if(amount < 0 || idx >= coins.size()) return 0;
    //      if(dp[amount][idx] != -1) return dp[amount][idx];
    //      int incl = solveMem(amount-coins[idx], coins, idx,dp);
    //      int excl = solveMem(amount, coins, idx+1,dp);
    //      return dp[amount][idx] = incl + excl;
    // }
    // int solveTab(int amount, vector<int>& coins){
    //      int n = coins.size();
    //      vector<vector<int>> dp(amount+1,vector<int>(n,0));
    //      for(int idx = 0; idx < n; idx++){
    //          dp[0][idx] = 1;
    //      }
    //      for(int a = 1; a <= amount; a++){
    //          for(int idx = n-1; idx >= 0; idx--){
    //              int incl = 0;
    //              if(a >= coins[idx]){
    //                  incl = dp[a-coins[idx]][idx];
    //              }
    //              int excl = 0;
    //              if(idx + 1 < n){
    //                  excl = dp[a][idx+1];
    //              }
    //              dp[a][idx] = incl + excl;
    //          }
    //      }
    //      return dp[amount][0];
    // }
    int solveFinal(int amount, vector<int>& coins){
        int n = coins.size();
        vector<unsigned long long> dp(amount+1,0);
        // 1 way to make amount 0
        dp[0] = 1;
        //dp[a] = number of ways to make amount a using the coins processed so far.
        for(int idx = 0; idx < coins.size(); idx++){
            for(int a = coins[idx]; a <= amount; a++){
                dp[a] += dp[a-coins[idx]];
            }
        }
        return dp[amount];
    }
public:
    int change(int amount, vector<int>& coins) {
        // int n = coins.size();
        // vector<vector<int>> dp(amount+1,vector<int>(n,-1));
        int ans = solveFinal(amount, coins);
        return ans;
    }
};