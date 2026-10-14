class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int n = nums.length;
        int[] ans= new int[n];
        Arrays.fill(ans,-1);
        Deque<Integer> st= new ArrayDeque<>();
        // for circular nature traverse the array 2 times
        for(int i= 2*n-1; i >= 0; i--){
            int idx =i%n;
            while(!st.isEmpty() && st.peek() <= nums[idx]){
                // remove all faltu elements
                st.pop();
            }
            // store greater elements
            if(i < n && !st.isEmpty()){
                ans[idx]=st.peek();
            }
            //element ko stack mein pudh toh krna hai hi
            st.push(nums[idx]);
        }
        return ans;
    }
}