
class Solution {
    public int minInsertions(String s) {

        int open = 0;
        int insertions = 0;

        for (int i = 0; i < s.length(); i++) {

            char ch = s.charAt(i);

            if (ch == '(') {
                open++;
            } 
            else {
                // We need two consecutive ')' for every '('

                if (i + 1 < s.length() && s.charAt(i + 1) == ')') {
                    // Found a pair '))'
                    i++;
                } 
                else {
                    // Only one ')' found, insert another ')'
                    insertions++;
                }

                // Match the closing pair with an opening '('
                if (open > 0) {
                    open--;
                } 
                else {
                    // No opening '(' available, insert one
                    insertions++;
                }
            }
        }

        // Every remaining '(' needs two ')'
        insertions += open * 2;

        return insertions;
    }
}