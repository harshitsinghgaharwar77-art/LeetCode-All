class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        if(k < 0) return 0;
        int n = nums.size();
        unordered_map<int, int> mpp;
        int l = 0, ans = 0;
        for(int r = 0; r < n; r++) {
            // current element ko include karo
            mpp[nums[r]]++;
            // window ko shrink karo agar k exceed ho gaya
            while(mpp.size() > k) {
                mpp[nums[l]]--;
                // map se entry delete karo
                if(mpp[nums[l]] == 0) {
                    mpp.erase(nums[l]);
                }
                l++;
            }
            // count all valid subarrays ending at r
            ans += (r-l+1);
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
};