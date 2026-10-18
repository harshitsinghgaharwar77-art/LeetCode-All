class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int oneCnt = 0, maxOne = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1) {
                oneCnt++;
                maxOne = max(maxOne, oneCnt);
            }
            else{
                oneCnt = 0;
            }
        }
        return maxOne;
    }
};