class Solution {

    static void solve(String digits, int idx, String[] mapping,
                      List<String> ans, StringBuilder output) {

        // Base case
        if (idx >= digits.length()) {
            ans.add(output.toString());
            return;
        }

        int value = digits.charAt(idx) - '0';
        String mapped = mapping[value];

        for (int i = 0; i < mapped.length(); i++) {
            output.append(mapped.charAt(i));
            solve(digits, idx + 1, mapping, ans, output);

            // Backtrack
            output.deleteCharAt(output.length() - 1);
        }
    }

    public List<String> letterCombinations(String digits) {

        List<String> ans = new ArrayList<>();

        if (digits.length() == 0)
            return ans;

        String[] mapping = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        StringBuilder output = new StringBuilder();

        solve(digits, 0, mapping, ans, output);

        return ans;
    }
}