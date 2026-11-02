
class Solution {
private:
    void solve(vector<int>& nums, vector<vector<int>> &ans, vector<int>& temp, int idx){
        // base case
        if(temp.size() >= 2){
            ans.push_back(temp);
        }

        // duplicates ko handle krne ke liye
        unordered_set<int> st;

        for(int i = idx; i < nums.size(); i++){
            // non decreasing condition
            if(!temp.empty() && nums[i] < temp.back()) continue;

            // duplicate handling
            if(st.count(nums[i])) continue;

            // set mein element ko insert kardo
            st.insert(nums[i]);

            // temp mein include karlo
            temp.push_back(nums[i]);

            // aage ke liye recursive call mardo
            solve(nums, ans, temp, i+1);

            // backtrack krlo
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(nums, ans, temp, 0);

        return ans;
    }
};
