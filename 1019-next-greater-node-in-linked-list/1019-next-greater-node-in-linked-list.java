/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int[] nextLargerNodes(ListNode head) {
        // linked list ko array mein convert karo
        List<Integer> list = new ArrayList<>();
        ListNode temp = head;
        while(temp != null){
            list.add(temp.val);
            temp = temp.next;
        }
        // main logic
        int n = list.size();
        int[] ans = new int[n];

        Deque<Integer> st = new ArrayDeque<>();
        for(int i = 0; i < n; i++){
            // for each index we will get the next graeter element
            // agar mera current element ya stack ke top wala elemenet se bada hai toh mujhe stacj k top ke index ki value ka answer mil gaya hai, answer store krliya stack ko pop karliya
            while(!st.isEmpty() && list.get(i) > list.get(st.peek())){
                int prevDay = st.pop();
                ans[prevDay] = list.get(i);
            }
            // current element ko stack mein store toh krwana hi hai
            st.push(i);
        }
        return ans;
    }
}