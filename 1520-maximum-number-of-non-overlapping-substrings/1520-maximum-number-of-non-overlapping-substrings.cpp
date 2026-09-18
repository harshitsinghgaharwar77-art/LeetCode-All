class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        // Store first and last occurrence of every character
        vector<int> first(26, n);
        vector<int> last(26, -1);

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';

            first[c] = min(first[c], i);
            last[c] = i;
        }

        vector<pair<int, int>> intervals;

        // Try to create a valid interval for every character
        for (int c = 0; c < 26; c++) {
            if (last[c] == -1)
                continue;

            int l = first[c];
            int r = last[c];
            bool valid = true;

            for (int i = l; i <= r; i++) {
                int curr = s[i] - 'a';

                // This character has an occurrence before l,
                // so we cannot make a valid substring starting at l.
                if (first[curr] < l) {
                    valid = false;
                    break;
                }

                // The current substring must include all
                // occurrences of this character.
                r = max(r, last[curr]);
            }

            if (valid) {
                intervals.push_back({l, r});
            }
        }

        // Sort by ending position
        sort(intervals.begin(), intervals.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second < b.second;
             });

        vector<string> ans;
        int prevEnd = -1;

        for (auto it : intervals) {
            int l = it.first;
            int r = it.second;

            // Non-overlapping
            if (l > prevEnd) {
                ans.push_back(s.substr(l, r - l + 1));
                prevEnd = r;
            }
        }

        return ans;
    }
};