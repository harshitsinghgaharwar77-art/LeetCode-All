class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0, 0, 0};

        for (int x : stones) {
            cnt[x % 3]++;
        }

        int zero = cnt[0];
        int one = cnt[1];
        int two = cnt[2];

        if (min(one, two) == 0) {
            return max(one, two) > 2 && zero % 2 == 1;
        }

        return abs(one - two) > 2 || zero % 2 == 0;
    }
};