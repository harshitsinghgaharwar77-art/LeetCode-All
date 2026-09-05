class Solution {
    List<String> ans = new ArrayList<>();

    public List<String> addOperators(String num, int target) {
        helper(num, target, 0, "", 0, 0);
        return ans;
    }

    private void helper(String s, int target, int i,
                         String path, long eval, long residual) {

        // Base case
        if (i == s.length()) {
            if (eval == target) {
                ans.add(path);
            }
            return;
        }

        String currStr = "";
        long currNum = 0;

        // Try all possible numbers starting from i
        for (int j = i; j < s.length(); j++) {

            // Don't allow leading zero
            if (j > i && s.charAt(i) == '0') {
                break;
            }

            currStr += s.charAt(j);
            currNum = currNum * 10 + (s.charAt(j) - '0');

            // First number
            if (i == 0) {
                helper(
                    s,
                    target,
                    j + 1,
                    path + currStr,
                    currNum,
                    currNum
                );
            } 
            else {

                // +
                helper(
                    s,
                    target,
                    j + 1,
                    path + "+" + currStr,
                    eval + currNum,
                    currNum
                );

                // -
                helper(
                    s,
                    target,
                    j + 1,
                    path + "-" + currStr,
                    eval - currNum,
                    -currNum
                );

                // *
                helper(
                    s,
                    target,
                    j + 1,
                    path + "*" + currStr,
                    eval - residual + residual * currNum,
                    residual * currNum
                );
            }
        }
    }
}