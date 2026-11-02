
class Solution {
public:
    int n;
    vector<string> ans;

    bool isValid(string str){
        if(str.size() > 1 && str[0] == '0') return false;
        int val = stoi(str);
        if(val > 255) return false;
        return true;
    }

    void solve(string &s, int idx, int parts, string curr){
        // base case
        if(idx == n && parts == 4){
            // piche wale extra decimal ko hatane ke liye
            curr.pop_back();
            ans.push_back(curr);
            return;
        }

        // pruning
        if(parts == 4 || idx >= n) return;

        // 1 no. ko include kr skte hai
        if(idx + 1 <= n)
            solve(s, idx+1, parts+1, curr + s.substr(idx,1) + ".");

        // 2 no. ko include kr skte hai
        if(idx + 2 <= n && isValid(s.substr(idx,2)))
            solve(s, idx+2, parts+1, curr + s.substr(idx,2) + ".");

        // 3 no. ko include kr skte hai
        if(idx + 3 <= n && isValid(s.substr(idx,3)))
            solve(s, idx+3, parts+1, curr + s.substr(idx,3) + ".");
    }

    vector<string> restoreIpAddresses(string s) {
        n = s.length();
        ans.clear();

        if(n < 4 || n > 12) return {};

        int parts = 0;
        string curr = "";

        solve(s, 0, parts, curr);

        return ans;
    }
};
