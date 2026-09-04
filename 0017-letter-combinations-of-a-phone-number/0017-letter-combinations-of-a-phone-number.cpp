class Solution {
    private:
    void solve(string &digits, vector<string> &ans, string &output, int idx, vector<string> &mapping){
        // base case
        if(idx >= digits.length()){
            // store valid answer
            ans.push_back(output);
            return;
        }
        int value = digits[idx] - '0';
        string mapped = mapping[value];
        for(int i = 0; i < mapped.length(); i++){
            output.push_back(mapped[i]);
            // recursive call
            solve(digits, ans, output, idx+1, mapping);
            // backtrack
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0)    return ans;
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string output = "";
        int idx = 0;
        solve(digits, ans, output, idx, mapping);
        return ans;
    }
};