class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int n = temperatures.length;
        int[] ans = new int[n];
        Deque<Integer> st = new ArrayDeque<>();
        for(int i = 0; i < n; i++){
            // for each index we wil find the answer using stack
            while(!st.isEmpty() && temperatures[i] > temperatures[st.peek()]){
                // i found a warmer day
                int prevDay = st.pop();
                ans[prevDay] = i-prevDay;
            }
            // after all this poping, mujhe current temperature to insert krna hi hai
            st.push(i);
        }
        return ans;
    }
}