
class Solution {
public:
    bool isValid(string s) {
        int count = 0;

        for (char ch : s) {
            if (ch == '(') {
                count++;
            }
            else if (ch == ')') {
                count--;

                if (count < 0) {
                    return false;
                }
            }
        }

        return count == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            // If a valid string is found at this level
            if (isValid(curr)) {
                ans.push_back(curr);
                found = true;
            }

            // Don't remove more parentheses once the minimum is found
            if (found) {
                continue;
            }

            // Generate strings by removing one parenthesis
            for (int i = 0; i < curr.size(); i++) {
                if (curr[i] != '(' && curr[i] != ')') {
                    continue;
                }

                string next = curr.substr(0, i) + curr.substr(i + 1);

                if (visited.find(next) == visited.end()) {
                    visited.insert(next);
                    q.push(next);
                }
            }
        }

        return ans;
    }
};