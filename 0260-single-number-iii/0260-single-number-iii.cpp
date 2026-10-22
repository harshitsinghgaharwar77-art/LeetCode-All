class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // vector<int> ans;
        // int n = nums.size();
        // unordered_map<int,int> mpp;
        // for(int num : nums) mpp[num]++;
        // for(int i = 0; i < n; i++){
        //     if(mpp[nums[i]] == 1) ans.push_back(nums[i]);
        // }
        // return ans;
        int xorred = 0;
        for(int num : nums) xorred ^= num;
        // find the exclusive bit
        int exBit = 0;
        while(true){
            if((xorred & 1) == 1){
                break;
            }
            xorred = xorred >> 1;
            exBit++;
        }
        int setBucket =0, unsetBucket = 0;
        for(int num : nums){
            // move set bit num to setBucket
            if(((num >> exBit)&1) == 1){
                setBucket ^= num;
            }else unsetBucket ^= num;
        }
        return {setBucket, unsetBucket};
    }
};