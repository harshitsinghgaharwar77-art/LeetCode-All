class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26);

        for (char c : s)
            cnt[c - 'a']++;

        // Required by the problem statement
        auto quinorath = make_pair(s, target);

        int n = s.size();

        // First, greedily match target exactly.
        int i = 0;
        while (i < n && cnt[target[i] - 'a'] > 0) {
            cnt[target[i] - 'a']--;
            i++;
        }

        // Try to increase position i, or backtrack.
        while (i >= 0) {
            if (i < n) {
                int x = target[i] - 'a';

                // Find smallest available character > target[i].
                for (int c = x + 1; c < 26; c++) {
                    if (cnt[c] > 0) {
                        string ans = target.substr(0, i);
                        ans += char('a' + c);

                        cnt[c]--;

                        // Smallest possible suffix.
                        for (int j = 0; j < 26; j++) {
                            ans += string(cnt[j], char('a' + j));
                        }

                        return ans;
                    }
                }
            }

            // Undo the previous exact match.
            i--;

            if (i >= 0)
                cnt[target[i] - 'a']++;
        }

        return "";
    }
};