class Solution {
    private:
    int isValid(vector<int>& nums, int k, int mid){
        int cnt = 1, len = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            if(len + nums[i] <= mid){
                len += nums[i];
            }else{
                cnt++;
                len = 0;
                if(cnt > k || nums[i] > mid){
                    return false;
                }else{
                    len += nums[i];
                }
            }
        }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int sum = 0, n = nums.size(), ans = -1;
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        int s = 0, e = sum;
        while(s <= e){
            int mid = s +(e-s)/2;
            if(isValid(nums, k, mid)){
                // store possible answer
                ans = mid;
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        return ans;
    }
};