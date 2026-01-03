class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        vector<int> arr = nums;

        unordered_map<int,int> mpp;

        long long distinct = 0;
        int x = 0;

        int mini = INT_MAX;

        for(int i = 0; i < nums.size(); i++){
            if(mpp[nums[i]] == 0){
                distinct = distinct + nums[i];
            }
            mpp[nums[i]]++;

            while(distinct >= k){
                mini = min(mini,i-x+1);
                mpp[nums[x]]--;
                if(mpp[nums[x]] == 0){
                    distinct = distinct - nums[x];
                }
                x++;
            }
        }
        if(mini == INT_MAX){
            return -1;
        }
        return mini;
    }
};