class Solution {
private:
    vector<int> factors(int x) {
        vector<int> res;
        for (int p = 2; p * p <= x; p++) {
            if (x % p == 0) {
                res.push_back(p);
                while (x % p == 0) {
                    x /= p;
                }
            }
        }
        if (x > 1)
            res.push_back(x);

        return res;
    }

public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        set<int> st;
        map<int, int> freq;

        int left = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {
            vector<int> pf = factors(nums[right]);
            for (int p : pf) {
                st.insert(p);
                freq[p]++;
            }

            while (st.size() > k) {
                vector<int> old = factors(nums[left]);
                for (int p : old) {
                    freq[p]--;
                    if (freq[p] == 0)
                        st.erase(p);
                }
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};