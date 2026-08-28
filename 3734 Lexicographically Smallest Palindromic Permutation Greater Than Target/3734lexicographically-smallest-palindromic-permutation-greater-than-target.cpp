class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }

        // More than one odd frequency => impossible
        int odd = 0;
        int mid = -1;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = i;
            }
        }

        if (odd > 1) return "";

        // Characters available for left half
        vector<int> half(26);
        for (int i = 0; i < 26; i++) {
            half[i] = cnt[i] / 2;
        }

        int m = n / 2;
        string left;

        for (int pos = 0; pos < m; pos++) {

            bool found = false;

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;

                half[c]--;
                left.push_back('a' + c);

                // Complete left half with largest possible characters
                string temp = left;

                for (int x = 25; x >= 0; x--) {
                    temp += string(half[x], 'a' + x);
                }

                // Make palindrome
                string pal = temp;

                if (mid != -1) {
                    pal += char('a' + mid);
                }

                for (int i = (int)temp.size() - 1; i >= 0; i--) {
                    pal += temp[i];
                }

                if (pal > target) {
                    found = true;
                    break;
                }

                // Undo
                left.pop_back();
                half[c]++;
            }

            if (!found)
                return "";
        }

        // Construct final palindrome
        string ans = left;

        if (mid != -1) {
            ans += char('a' + mid);
        }

        for (int i = m - 1; i >= 0; i--) {
            ans += left[i];
        }

        if (ans > target)
            return ans;

        return "";
    }
};