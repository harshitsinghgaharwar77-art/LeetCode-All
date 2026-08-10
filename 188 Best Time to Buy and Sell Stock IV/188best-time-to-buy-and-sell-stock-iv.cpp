class Solution {
    private:
    // taken from best time to buy and sell stock leetcode 4
    int solve(vector<int>& prices, int k){
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(k+1,0));
        vector<vector<int>> next(2, vector<int>(k+1,0));
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int limit = 1; limit <= k; limit++) {
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
        return next[1][k];
    }

    // More optimised
    int solveMoreOptimised(vector<int>& prices, int k){
        int n = prices.size();
        vector<int> curr(2*k+1, 0);
        vector<int> next(2*k+1, 0);

        for(int idx = n-1; idx >= 0; idx--){
            for(int operationNo = 0; operationNo < 2*k; operationNo++){
                int profit = 0;
                if(operationNo%2 == 0){
                    int buyKaro = -prices[idx] + next[operationNo+1];
                    int skipKaro = 0 + next[operationNo];
                    profit = max(buyKaro, skipKaro);
                }
                else{
                    int sellKaro = prices[idx] + next[operationNo+1];
                    int skipKaro = 0 + next[operationNo];
                    profit = max(sellKaro, skipKaro);
                }
                curr[operationNo] = profit;
            }
            next = curr;
        }
        return next[0];
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        return solveMoreOptimised(prices,k);
    }
};