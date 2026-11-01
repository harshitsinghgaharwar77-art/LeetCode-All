class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        // sliding window
        int l = 0, r = 0, cnt = 0;
        vector<int> freq(3,0);
        while(r < n){
            // current element ko window mein include karo
            freq[s[r]-'a']++;
            // occurence check karo
            while(freq[0] > 0 && freq[1] > 0 && freq[2] > 0){
                // count ko increment karo
                cnt += (n-r);
                // window ko shrink karo
                freq[s[l]-'a']--;
                l++;
            }
            r++;
        }
        return cnt;
    }
};