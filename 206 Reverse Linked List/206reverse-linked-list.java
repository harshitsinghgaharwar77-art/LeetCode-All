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
    public ListNode solve(ListNode prev, ListNode curr) {

        // Base case
        if (curr == null) {
            return prev;
        }

        // Save next node
        ListNode forward = curr.next;

        // Reverse the link
        curr.next = prev;

        // Recursive call
        return solve(curr, forward);
    }
    public ListNode reverseList(ListNode head) {
        // Iterative approach

        // ListNode prev = null;
        // ListNode curr = head;

        // while(curr != null){
        //     ListNode forward = curr.next;

        //     curr.next = prev;
        //     prev = curr;
        //     curr = forward;
        // }
        // return prev;



        // Recursive approach
        ListNode prev = null;
        ListNode curr = head;
        ListNode ans = solve(prev, curr);
        return ans;
    }
}