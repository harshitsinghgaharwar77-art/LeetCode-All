class Solution {
    private:
    void solve(vector<vector<int>> &ans, vector<int> &temp, int n, int k, int start){
        // base case
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }
        // start se shuru krke har ek number ko check karenge
        for(int i = start; i <= n; i++){
            // include karo
            temp.push_back(i);
            // ercursive call maro aage ke liye
            solve(ans, temp, n, k, i+1);
            // backtrack karo
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        // start : 1 se start karenge
        solve(ans, temp, n, k, 1);
        return ans;
    }
};