class Solution {
    public String removeKdigits(String num, int k) {
        Deque<Character> st = new ArrayDeque<>();

        // apply monotonic stack pattern on input string
        for(char ch : num.toCharArray()){
            while(!st.isEmpty() && k > 0 && st.peek() > ch){
                st.pop();
                k--;
            }
            // insert the current character
            st.push(ch);
        }
        // step-2: agar kuch removals still pending h, toh take care of it
        while(k > 0 && !st.isEmpty()){
            st.pop();
            k--;
        }
        // step-3: build ans string, reverse it, remove leading zeroes
        StringBuilder ans = new StringBuilder();
        while(!st.isEmpty()){
            ans.append(st.peek());
            st.pop();
        }
        // reverse the stringbuilder
        ans.reverse();
        // remove the leading zeroes
        int idx = 0;
        while(idx < ans.length() && ans.charAt(idx) == '0'){
            idx++;
        }
        String res = ans.substring(idx);
        if(res.length() == 0){
            return "0";
        }
        else{
            return res;
        }
    }
}