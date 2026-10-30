class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        for(int i = 0; i < n; i++){
            if((to_string(nums[i]).length() & 1) == 0) cnt++;
        }
        return cnt;
    }
};