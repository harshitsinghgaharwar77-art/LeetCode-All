class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int s = seat[1];

            if (s >= 2 && s <= 9) {
                mp[row] |= (1 << s);
            }
        }

        long long ans = 2LL * (n - mp.size());

        for (auto &[row, mask] : mp) {
            bool left = true;
            bool middle = true;
            bool right = true;

            for (int s = 2; s <= 5; s++) {
                if (mask & (1 << s)) {
                    left = false;
                    break;
                }
            }

            for (int s = 4; s <= 7; s++) {
                if (mask & (1 << s)) {
                    middle = false;
                    break;
                }
            }

            for (int s = 6; s <= 9; s++) {
                if (mask & (1 << s)) {
                    right = false;
                    break;
                }
            }

            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }

        return ans;
    }
};