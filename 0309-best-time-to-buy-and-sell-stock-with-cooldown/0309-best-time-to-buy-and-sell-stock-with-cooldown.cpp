class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> curr(2, 0);
        vector<int> next(2, 0);
        vector<int> next2(2, 0); // for cooldown

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int buy = 0; buy <= 1; buy++) {

                int profit = 0;

                if (buy) {
                    int buyKaro = -prices[idx] + next[0];
                    int ignoreKaro = 0 + next[1];

                    profit = max(buyKaro, ignoreKaro);
                } else {
                    int sellKaro = prices[idx] + next2[1]; // for cooldown
                    int ignoreKaro = 0 + next[0];

                    profit = max(sellKaro, ignoreKaro);
                }

                curr[buy] = profit;
            }

            next2 = next;
            next = curr;
        }

        return next[1];
    }
};