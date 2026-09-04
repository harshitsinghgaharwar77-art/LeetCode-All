class Solution {
    private:
    void solve(vector<int>& nums, int idx, vector<int>& output, vector<vector<int>>& ans){
        // base case
        if(idx >= nums.size()){
            // valid answer
            ans.push_back(output);
            return;
        }
        int currVal = nums[idx];
        // include 
        output.push_back(currVal);
        solve(nums, idx+1, output, ans);
        //exclude
        output.pop_back();  // backtrack
        solve(nums, idx+1, output, ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int idx = 0;
        solve(nums, idx, output, ans);
        return ans;
    }
};