class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = count(s.begin(), s.end(), '1');
        int zeros = s.size()-ones;
        return string(ones - 1, '1') + string(zeros, '0') + "1";
    }
};