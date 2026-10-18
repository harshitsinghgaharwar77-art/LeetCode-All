class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length(), m = t.length();
        if(m > n) return "";
        unordered_map<char, int> mpp;
        // store freq of t in mpp
        for(char &ch : t) mpp[ch]++;

        int reqCnt = m, i = 0, j = 0, winSiz = INT_MAX, start_i = 0;
        while(j < n){
            char ch = s[j];
            if(mpp[ch] > 0){
                reqCnt--;
            }
            mpp[ch]--;
            while(reqCnt == 0){
                // start shrinking the window
                int currWinSiz = j-i+1;
                if(winSiz > currWinSiz){
                    winSiz = currWinSiz;
                    start_i = i;
                }
                mpp[s[i]]++;
                if(mpp[s[i]] > 0){
                    reqCnt++;
                }
                i++;
            }
            j++;
        }
        return winSiz == INT_MAX ? "" : s.substr(start_i,winSiz);
    }
};