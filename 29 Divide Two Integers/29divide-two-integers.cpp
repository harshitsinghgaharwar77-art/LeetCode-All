class Solution {
public:
    int divide(int dividend, int divisor) {

        // edge case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        if (dividend == divisor) {
            return 1;
        }

        bool sign = true;

        // check the sign of the answer
        if (dividend <= 0 && divisor > 0)
            sign = false;
        else if (dividend >= 0 && divisor < 0)
            sign = false;

        // convert to long long before taking abs
        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);

        // take +ve value
        long long quotient = 0;

        while (n >= d) {

            int cnt = 0;

            // find the largest power of 2 such that
            // d * 2^cnt is less than or equal to n
            while (n >= (d << (cnt + 1))) {
                cnt += 1;
            }

            quotient += (1LL << cnt);
            n -= (d << cnt);
        }

        // return the answer according to the sign
        return sign ? quotient : -quotient;
    }
};