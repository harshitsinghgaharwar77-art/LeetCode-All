class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(2 * nums.size());
        int k = 0;
        for(int i = 0; i < nums.size(); i++){
            ans[k++] = nums[i];
        }
        for(int i = 0; i < nums.size(); i++){
            ans[k++] = nums[i];
        }
        return ans;
    }
};