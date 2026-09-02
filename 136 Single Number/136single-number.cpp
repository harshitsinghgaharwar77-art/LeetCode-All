class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorSum = 0;
        for(int num : nums){
            xorSum ^= num;
        }
        return xorSum;
    }
};