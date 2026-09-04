class Solution {
    private:

    bool isPlaindrome(string s, int start, int end){
        while(start < end){
            if(s[start] != s[end]){
                return false;
            }

            start++;
            end--;
        }

        return true;
    }

    void solve(string& s, int idx, vector<vector<string>> &ans, vector<string> &output){
        // base case
        if(idx >= s.length()){
            ans.push_back(output);
            return;
        }

        // try every possible substring
        for(int i = idx; i < s.length(); i++){

            // check if s[idx...i] is a palindrome
            if(isPlaindrome(s, idx, i)){

                // include
                output.push_back(s.substr(idx, i - idx + 1));

                // recursive call
                solve(s, i + 1, ans, output);

                // backtrack
                output.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> output;

        solve(s, 0, ans, output);

        return ans;
    }
};