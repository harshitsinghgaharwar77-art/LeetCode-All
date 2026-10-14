class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int n = nums1.length, m = nums2.length;
        Deque<Integer> st = new ArrayDeque<>();
        HashMap<Integer, Integer> mpp = new HashMap<>();
        int[] ans = new int[n];
        
        // process answer for each element in. ums2
        for(int i = m-1; i >= 0; i--){
            // pop smaller elements
            while(!st.isEmpty() && st.peek() <= nums2[i]){
                st.pop();
            }
            // store the greatest element in stack
            mpp.put(nums2[i], st.isEmpty() ? -1 : st.peek());
            // current element ko toh insert krna hi hai
            st.push(nums2[i]);
        }
        // build the answer for nusm1
        for(int i = 0; i < n; i++){
            ans[i] = mpp.get(nums1[i]);
        }
        return ans;
    }
}