class Solution {
public:
    bool isPalindromic(string s) {
        string binary = "";
        for (char c : s) {
            int x = c;
            for (int i = 7; i >= 0; i--) {
                binary += ((x >> i) & 1) + '0';
            }
        }
        int l = 0;
        int r = binary.size() - 1;
        while (l < r) {
            if (binary[l] != binary[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};