class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int, int> mpp;  // to keep track of the elements
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int num = nums[i];
            int moreNeeded = target - nums[i];
            // finding moreneeded in map
            if(mpp.find(moreNeeded) != mpp.end()){
                return {mpp[moreNeeded], i};
            }
            // if not found store new value in map
            mpp[num] = i;
        }
        return {-1, -1};
    }
};