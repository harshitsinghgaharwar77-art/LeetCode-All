class Solution {
    // taken from leetcode best time to buy and sell stock 4
    int solve(vector<int>& prices, int fee){
        int n = prices.size();
        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        for(int idx = n-1; idx >= 0; idx--){
            for(int buy = 0; buy <= 1; buy++){
                int profit = 0;
                if(buy){
                    int buyKaro = -prices[idx] + next[0];
                    int skipKaro = 0 + next[1];
                    profit = max(buyKaro, skipKaro);
                }
                else{
                    int sellKaro = prices[idx] + next[1]-fee;
                    int skipKaro = 0 + next[0];
                    profit = max(sellKaro, skipKaro);
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return next[1];
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        return solve(prices, fee);
    }
};