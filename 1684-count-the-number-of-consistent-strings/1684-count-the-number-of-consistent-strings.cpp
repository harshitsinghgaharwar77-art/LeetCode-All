class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> freq(26, false);
        for(auto &ch : allowed) {
            freq[ch - 'a'] = true;
        }
        int cnt = 0;
        for(auto &word : words) {
            bool flag = true;
            for(auto &ch : word) {
                if(!freq[ch - 'a']) {
                    flag = false;
                    break;
                }
            }
            if(flag) cnt++;
        }
        return cnt;
    }
};