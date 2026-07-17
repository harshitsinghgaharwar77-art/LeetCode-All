class Solution {
    private:
    void solve(int opn_cnt, int clsd_cnt, int n, string output, vector<string>& ans){
        // base case
        if(output.length() == 2*n){
            ans.push_back(output);
            return;
        }
        // recursive calls
        if(opn_cnt < n){
            solve(opn_cnt+1, clsd_cnt, n,output+"(",ans);
        }
        if(clsd_cnt < opn_cnt){
            solve(opn_cnt, clsd_cnt+1, n,output+")",ans);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(0,0,n,"",ans);
        return ans;
    }
};