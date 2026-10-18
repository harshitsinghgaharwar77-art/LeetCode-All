class Solution {
    public int lengthOfLongestSubstring(String s) {
        int maxLength = 0, i = 0;
        Set<Character> st = new HashSet<>();
        for(int j = 0; j < s.length(); j++){
            while(st.contains(s.charAt(j))){
                st.remove(s.charAt(i));
                i++;
            }
            st.add(s.charAt(j));
            maxLength = Math.max(maxLength, j-i+1);
        }
        return maxLength;
    }
}