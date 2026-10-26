class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(n,1); // count of LIS
        vector<int> t(n,1); // LIS ending at i
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    if(t[j] + 1 == t[i]){
                        cnt[i] += cnt[j];
                    }else if(t[j] + 1 > t[i]) {
                        t[i] = t[j] + 1;
                        cnt[i] =cnt[j];
                    }
                }
            }
        }
        int maxi = *max_element(begin(t), end(t));
        int ans = 0;
        for(int i =0; i < n; i++){
            if(t[i] == maxi) ans += cnt[i];
        }
        return ans;
    }
};