class Solution {
    private:
    void solve(int open, int close, int n, vector<string>& ans, string &output){
        // base case
        if(2*n == output.length()){
            // valid answer found 
            ans.push_back(output);
            return;
        }
        // add ( when we still have opening brackets left
        if(open < n){
            output.push_back('(');
            solve(open+1, close, n, ans, output);
            // backtrack
            output.pop_back();
        }
        // add ) when we still have closing & ( bracket
        if(close < open){
            output.push_back(')');
            solve(open, close+1, n, ans, output);
            output.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        if(n == 1)  return {"()"};
        vector<string> ans;
        string output = "";
        solve(0,0,n, ans, output);
        return ans;
    }
};