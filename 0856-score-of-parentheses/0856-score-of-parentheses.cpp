
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        for(char c : s) {
            if(c == '(') {
                st.push(0);
            }
            else {
                int curr = st.top();
                st.pop();

                int val = max(1, 2 * curr);

                st.top() += val;
            }
        }

        return st.top();
    }
};