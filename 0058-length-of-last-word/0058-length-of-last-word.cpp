class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length() - 1;
        int cnt = 0;
        // remove whitespaces
        while (n >= 0 && s[n] == ' ') n--;
        // cnt chr of lst word
        while (n >= 0 && s[n] != ' ') {
            cnt++;
            n--;
        }
        return cnt;
    }
};