class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        // compute the power of 2 array
        vector<int> powOf2(n);
        const int MOD = 1e9 + 7;
        powOf2[0] = 1;
        for(int i = 1; i < n; i++){
            powOf2[i] = (2LL * powOf2[i-1]) % MOD;
        }
        int left = 0, right = n-1, ans = 0;
        while(left <= right){
            if(nums[left] + nums[right] <= target){
                ans = (ans + powOf2[right - left]) % MOD;
                left++;
            }else{
                right--;
            }
        }
        return ans;
    }
};