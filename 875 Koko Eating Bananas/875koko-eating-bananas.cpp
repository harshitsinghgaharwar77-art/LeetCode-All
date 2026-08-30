class Solution {
private:
    bool isValid(vector<int>& piles, int h, int k) {
        long long hours = 0;
        for (int i = 0; i < piles.size(); i++) {
            hours += (piles[i] + k - 1) / k;
            if (hours > h)
                return false;
        }
        return true;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = -1;
        int n = piles.size();
        for (int i = 0; i < n; i++) {
            if (maxi < piles[i]) {
                maxi = piles[i];
            }
        }
        int s = 1, e = maxi, ans = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (isValid(piles, h, mid)) {
                // store possible answer
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};