class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;

        // 1. Skip leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // If only spaces
        if (i == n) return 0;

        // 2. Handle sign
        int sign = 1;

        if (s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (s[i] == '+') {
            i++;
        }

        // 3. Convert digits
        long long ans = 0;

        while (i < n && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');

            // 4. Check overflow
            if (sign == 1 && ans > INT_MAX) {
                return INT_MAX;
            }

            if (sign == -1 && -ans < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        return (int)(sign * ans);
    }
};