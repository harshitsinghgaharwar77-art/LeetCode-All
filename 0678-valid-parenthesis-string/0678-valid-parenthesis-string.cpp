class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;

        for (char c : s) {

            if (c == '(') {
                low++;
                high++;
            }
            else if (c == ')') {
                low--;
                high--;
            }
            else { // '*'
                low--;      // '*' as ')'
                high++;     // '*' as '('
            }

            // We cannot have negative minimum.
            if (low < 0) {
                low = 0;
            }

            // Even the maximum possible opens became negative.
            if (high < 0) {
                return false;
            }
        }

        return low == 0;
    }
};