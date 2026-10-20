class Solution {
    private:
    void solve(vector<int>& nums, vector<int>& temp, vector<vector<int>> &ans,unordered_map<int,int> &mpp,int n){
        // base case
        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }
        for(auto [num, cnt] : mpp){
            if(cnt == 0) continue;
            temp.push_back(num);
            mpp[num]--;
            solve(nums,temp,ans,mpp,n);
            temp.pop_back();
            mpp[num]++;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        vector<vector<int>> ans;
        vector<int> temp;
        // store the freq of every element in map
        for(int i : nums) mpp[i]++;
        solve(nums, temp, ans,mpp,n);
        return ans;
    }
};