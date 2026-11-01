class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        vector<int> freq(26,0);
        int maxFreq =0 , maxLen = 0,l=0,r=0;
        while(r < n){
            // current element ko window mein add karo
            freq[s[r]-'A']++;
            // max freq in current window
            maxFreq = max(maxFreq, freq[s[r]-'A']);
            // shrink karo current window ko
            while((r-l+1) - maxFreq > k){
                freq[s[l]-'A']--;
                l++;
            }
            // maxLen ko update karo
            maxLen = max(maxLen, (r-l+1));
            r++;
        }
        return maxLen;
    }
};