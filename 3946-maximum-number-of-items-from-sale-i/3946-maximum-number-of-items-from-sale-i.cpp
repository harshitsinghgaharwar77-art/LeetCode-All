
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> groups[1501];

        // Step 1: Calculate contribution of every item
        for (int i = 0; i < n; i++) {
            int freeCopies = 0;

            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    freeCopies++;
                }
            }

            int weight = freeCopies + 1;
            int price = items[i][1];

            if (price <= budget) {
                groups[price].push_back(weight);
            }
        }

        const int NEG = -1e9;
        vector<int> dp(budget + 1, NEG);

        dp[0] = 0;

        int ans = 0;

        // Step 2: Process prices in descending order
        for (int p = budget; p >= 1; p--) {

            auto& v = groups[p];

            sort(v.rbegin(), v.rend());

            int m = v.size();

            // Prefix sum of top k contributions
            vector<int> pref(m + 1, 0);

            for (int k = 1; k <= m; k++) {
                pref[k] = pref[k - 1] + v[k - 1];
            }

            // Step 3: Select at least one item of price p
            for (int k = 1; k <= m && k * p <= budget; k++) {

                int cost = k * p;

                for (int c = 0; c + cost <= budget; c++) {

                    if (dp[c] == NEG) continue;

                    int remaining = budget - c - cost;
                    int extra = remaining / p;

                    int total = dp[c] + pref[k] + extra;

                    ans = max(ans, total);
                }
            }

            // Step 4: 0/1 Knapsack update
            for (int w : v) {
                for (int c = budget; c >= p; c--) {

                    if (dp[c - p] != NEG) {
                        dp[c] = max(dp[c], dp[c - p] + w);
                    }
                }
            }
        }

        return ans;
    }
};
