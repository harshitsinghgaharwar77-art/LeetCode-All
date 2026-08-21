class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN, maxSum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            // step-1: creating sum
            maxSum = maxSum + nums[i];
            // step-2: updating sum
            maxi = max(maxSum, maxi);
            //ste-3: check if sum id negative
            if(maxSum < 0){
                maxSum = 0;
            }
        } 
        return maxi;  
    }
};