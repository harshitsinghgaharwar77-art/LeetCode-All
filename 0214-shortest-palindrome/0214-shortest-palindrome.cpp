class Solution {
    private:
    // function to compute th LPS (Longest Proper Prefix which is also Suffix) array
    void computeLPS(string pattern, vector<int> &lps){
        int m = pattern.length();
        // Length of the previous longest prefix & suffix
        int len = 0;
        // because there is no proper suffix and prefix of pattern[0..0]
        lps[0] = 0;
        int i = 1;
        while(i < m){
            if(pattern[i] == pattern[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len != 0){
                    len = lps[len-1];   // you can also write, len = len - 1;
                }else{
                    lps[i] = 0;
                    i++;  // FIX: increment i to avoid infinite loop
                }
            }
        }
    }

public:
    string shortestPalindrome(string s) {
        int n = s.length();
        if(n == 0) return "";
        string rev = s;
        reverse(rev.begin(), rev.end());
        string temp = s + "_" + rev;
        vector<int> LPS(temp.length(), 0);
        computeLPS(temp, LPS);
        int longestLPSLength = LPS[temp.length()-1];    // temp.back();
        string culprit = rev.substr(0,s.length()-longestLPSLength);
        return culprit + s;
    }
};