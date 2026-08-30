class Solution {
private:
    bool isValid(vector<int>& weights, int days, int maxWeight) {
        int day = 1;
        int shippedCapacity = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (shippedCapacity + weights[i] > maxWeight) {
                // move to next day
                day++;
                shippedCapacity = weights[i];
            } else {
                shippedCapacity += weights[i];
            }
        }
        return day <= days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size(), maxi = -1;
        for (int i = 0; i < n; i++) {
            if (maxi < weights[i]) {
                maxi = weights[i];
            }
        }
        // required capacity lies between single maximum weight and sum of all
        // weights
        int s = maxi, e = 0;
        for (int i = 0; i < n; i++) {
            e += weights[i];
        }
        int ans = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (isValid(weights, days, mid)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};