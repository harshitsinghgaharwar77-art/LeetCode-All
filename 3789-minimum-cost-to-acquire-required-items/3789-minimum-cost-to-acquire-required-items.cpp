
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        
        long long ans = 0;

        // Option 1: Buy only individual items
        long long option1 = 1LL * cost1 * need1 + 1LL * cost2 * need2;

        // Option 2: Buy type 3 items for the common requirement
        int common = min(need1, need2);
        
        long long option2 = 1LL * common * costBoth
                          + 1LL * (need1 - common) * cost1
                          + 1LL * (need2 - common) * cost2;

        // Option 3: Buy type 3 items for the entire maximum requirement
        long long option3 = 1LL * max(need1, need2) * costBoth;

        return min({option1, option2, option3});
    }
};
