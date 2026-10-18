
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int n = nums.size();
        int prod = 1, cnt = 0, j = 0;
        for(int i = 0; i < n; i++){
            prod *= nums[i];
            while(prod >= k){
                prod /= nums[j];
                j++;
            }
            cnt += i - j + 1;
        }
        return cnt;
    }
};
