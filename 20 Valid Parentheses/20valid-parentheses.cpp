class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        // Optional small optimization:
        if (s.size() % 2 == 1) return false;

        for (char c : s) {
            if (c == '(') st.push(')');
            else if (c == '{') st.push('}');
            else if (c == '[') st.push(']');
            else {
                if (st.empty() || st.top() != c) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};