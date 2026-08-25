class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<bool> present(101, false);

        for (int x : nums) {
            present[x] = true;
        }

        for (int x = k; ; x += k) {
            if (x > 100 || !present[x]) {
                return x;
            }
        }
    }
};