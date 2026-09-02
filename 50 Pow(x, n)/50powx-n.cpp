class Solution {
public:
    double myPow(double x, int n) {
        // edge case
        if (x == 0)
            return 0;
        long long power = n;
        if (n < 0) {
            // power is negative
            x = 1 / x;
            power = -power;
        }
        double ans = 1;
        while (power > 0) {

            // If current bit is 1
            if (power & 1) {
                ans = ans * x;
            }

            // Square the base
            x = x * x;

            // Move to next bit
            power = power >> 1;
        }

        return ans;
    }
};