class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size(), cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i < j && nums[i] + nums[j] < target){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};