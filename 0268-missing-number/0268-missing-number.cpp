class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int a = n*(n+1)/2;
        int b = 0;
        for(int i : nums) b += i;
        return a-b;
    }
};