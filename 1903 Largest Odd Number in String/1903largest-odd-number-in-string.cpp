class Solution {
public:
    string largestOddNumber(string num) {
         // Traverse from the end of the string to the beginning
        for (int i = num.length() - 1; i >= 0; --i) {
            // Check if the current digit is odd
            if ((num[i] - '0') % 2 != 0) {
                // Return the prefix up to this odd digit
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};