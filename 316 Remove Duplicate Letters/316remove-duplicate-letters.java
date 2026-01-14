class Solution {
    public String removeDuplicateLetters(String s) {

        int[] freq = new int[26];
        boolean[] present = new boolean[26];

        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }

        Stack<Character> stack = new Stack<>();

        for (char c : s.toCharArray()) {
            freq[c - 'a']--;

            if (present[c - 'a']) continue;

            while (!stack.isEmpty()
                    && stack.peek() > c
                    && freq[stack.peek() - 'a'] > 0) {

                present[stack.pop() - 'a'] = false;
            }

            stack.push(c);
            present[c - 'a'] = true;
        }

        StringBuilder ans = new StringBuilder();
        for (char c : stack) ans.append(c);

        return ans.toString();
    }
}
