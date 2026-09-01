class Solution {
    public String reverseWords(String s) {
        StringBuilder ans = new StringBuilder();
        int i = s.length()-1;
        while(i >= 0){
            // removing all the trailing spaces
            while(i >= 0 && s.charAt(i) == ' '){
                i--;
            }
            // check the value of i
            if(i < 0){
                // invalid index;
                break;
            }
            int j = i;
            // find the start index of the word
            while(j >= 0 && s.charAt(j) != ' '){
                j--;
            }
            // append the word in the string
            ans.append(s.substring(j+1,i+1));
            while(j >= 0 && s.charAt(j) == ' '){
                j--;
            }
            if(j >= 0){
                // need space
                ans.append(' ');
            }
            i = j;
        }
        return ans.toString();
    }
}