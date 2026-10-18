
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), oddCnt = 0, prevCnt = 0, ans = 0, i = 0, j = 0;
        while(j < n){
            if((nums[j] & 1) == 1){
                oddCnt++;
                prevCnt = 0;
            }
            while(oddCnt == k){
                prevCnt++;
                if((nums[i] & 1) == 1){
                    oddCnt--;
                }
                i++;
            }
            ans += prevCnt;
            j++;
        }
        return ans;
    }
};
