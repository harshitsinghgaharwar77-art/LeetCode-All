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
    public ListNode middleNode(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;

        while(fast != null){
            fast = fast.next;

            if(fast != null){
                fast = fast.next;
                slow = slow.next;
            }
        }

        return slow;
    }

    public ListNode deleteMiddle(ListNode head) {
        if(head == null || head.next == null){
            return null;
        }

        ListNode middle = middleNode(head);
        ListNode temp = head;

        while(temp.next != middle){
            temp = temp.next;
        }

        temp.next = middle.next;

        return head;
    }
}