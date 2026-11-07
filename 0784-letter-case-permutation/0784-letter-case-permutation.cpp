class Solution {
private:
    void solve(string s, string &output, vector<string>& ans, int idx, int n){
        // base case
        if(idx >= n){
            ans.push_back(output);
            return;
        }

        if(isalpha(s[idx])){
            // make capital
            char currVal = toupper(s[idx]);
            output.push_back(currVal);
            solve(s, output, ans, idx+1, n);
            output.pop_back();

            // donot make capital
            currVal = tolower(s[idx]);
            output.push_back(currVal);
            solve(s, output, ans, idx+1, n);
            output.pop_back();
        }
        else{
            output.push_back(s[idx]);
            solve(s, output, ans, idx+1, n);
            output.pop_back();
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        int n = s.length();
        string output = "";
        int idx = 0;
        solve(s, output, ans, idx, n);
        return ans;
    }
};