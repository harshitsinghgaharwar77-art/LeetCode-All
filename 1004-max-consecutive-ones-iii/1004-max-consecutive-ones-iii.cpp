class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        // approach: sliding window + two pointers
        int l = 0, r = 0, zeroes = 0, maxLen = 0;
        while(r < n){
            if(nums[r] == 0) zeroes++;
            while (zeroes > k)
            {
                if (nums[l] == 0)
                {
                    zeroes--;
                }
                l++;
            }
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};