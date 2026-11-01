class Solution {
    public String sortSentence(String s) {
        // Map to store the words in correct order
        Map<Integer, String> mpp = new HashMap<>();
        // split each word on the basis of space
        for(String str : s.split(" ")){
            int lastIdx = str.length()-1;
            // get the word and the index separately
            int idx = str.charAt(lastIdx)-'0';
            String actualWord = str.substring(0,lastIdx);
            // map mein add krdo
            mpp.put(idx, actualWord);
        }
        // Build the answer :)
        StringBuilder ans = new StringBuilder();
        for(int i = 1; i <= mpp.size(); i++){
            ans.append(mpp.get(i));
            ans.append(" ");
        }
        return ans.toString().trim();
    }
}