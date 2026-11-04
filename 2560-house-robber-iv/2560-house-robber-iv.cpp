class Solution {
private:
    bool isPossible(vector<int>& nums, int k, int mid){
        int n = nums.size(), cnt = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] <= mid){
                cnt++;
                i++;// skip adj house
            }
        }
        return cnt >= k;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        int s = *min_element(nums.begin(), nums.end());
        int e = *max_element(nums.begin(), nums.end());
        int ans = -1;
        while(s <= e){
            int mid = s + (e-s)/2;
            if(isPossible(nums, k, mid)){
                ans = mid;
                e = mid - 1;
            }else s = mid + 1;
        }
        return ans;
    }
};