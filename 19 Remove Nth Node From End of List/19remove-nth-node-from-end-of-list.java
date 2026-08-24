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
// Sliding window
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        
        // Dummy node handles the case where head itself is removed
        ListNode dummy = new ListNode(0);
        dummy.next = head;

        ListNode prev = dummy;
        ListNode curr = head;

        // Move curr n nodes ahead
        for (int i = 1; i <= n; i++) {
            curr = curr.next;
        }

        // Move both pointers until curr reaches the end
        while (curr != null) {
            prev = prev.next;
            curr = curr.next;
        }

        // Remove the nth node from the end
        prev.next = prev.next.next;

        return dummy.next;
    }
}