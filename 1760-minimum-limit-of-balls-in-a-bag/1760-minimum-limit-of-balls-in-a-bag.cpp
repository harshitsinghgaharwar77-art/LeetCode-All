class Solution {
private:
    bool isPossible(vector<int>& nums, int mid, int maxOperations){
        int n = nums.size(), operations = 0;
        for(int i = 0; i < n; i++){
            operations += (nums[i]-1)/mid;
            if(operations > maxOperations) return false;
        }
        return true;
    }

public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int s = 1, e = *max_element(nums.begin(), nums.end());
        int ans = e;
        while(s <= e){
            int mid = s + (e-s)/2;
            if(isPossible(nums,mid,maxOperations)){
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return ans;
    }
};