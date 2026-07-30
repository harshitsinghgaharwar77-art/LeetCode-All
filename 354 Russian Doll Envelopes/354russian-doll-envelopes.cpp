class Solution {
private:
    static bool myCmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }

    int solve(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), myCmp);

        vector<int> ans;

        for (auto &env : envelopes) {
            int h = env[1];

            if (ans.empty() || h > ans.back()) {
                ans.push_back(h);
            } else {
                auto it = lower_bound(ans.begin(), ans.end(), h);
                *it = h;
            }
        }

        return ans.size();
    }

public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        return solve(envelopes);
    }
};