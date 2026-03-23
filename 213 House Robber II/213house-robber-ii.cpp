class Solution {
    private:
    int solve(vector<int>& nums)
    {
        int n = nums.size();
        int prev2 = 0;
        int prev1 = nums[0];
        for(int i = 1; i < n; i++)
        {
            int incl = prev2 + nums[i];
            int excl = prev1 + 0;
            int curr = max(incl,excl);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // base case
        if(n == 1)
        {
            return nums[0];
        }
        vector<int> first,sec;
        for(int i = 0; i < n; i++)
        {
            if(i != n-1)
            {
                first.push_back(nums[i]);
            }
            if(i != 0)
            {
                sec.push_back(nums[i]);
            }
        }
        return max(solve(first),solve(sec));
    }
};