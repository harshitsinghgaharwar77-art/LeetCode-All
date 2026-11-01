class Solution {
    private:
    int atMost(vector<int>& nums, int k){
        if(k < 0) return 0;
        // sliding window
        int n = nums.size();
        int l = 0, r =0, cnt = 0, odd =0;
        for(int r =0 ; r < n; r++){
            // count odd numbers
            if(nums[r] % 2 != 0) odd++;
            // shrink window size when odd > k
            while(odd > k){
                if(nums[l] % 2 != 0) odd--;
                l++;
            }
            // count all valid subaarys ending at r
            cnt += (r-l+1);
        }
        return cnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};