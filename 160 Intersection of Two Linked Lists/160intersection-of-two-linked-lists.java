/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {

        if (headA == null || headB == null) {
            return null;
        }

        // Find lengths
        int lenA = 0;
        int lenB = 0;

        ListNode a = headA;
        ListNode b = headB;

        while (a != null) {
            lenA++;
            a = a.next;
        }

        while (b != null) {
            lenB++;
            b = b.next;
        }

        // Move the pointer of the longer list ahead
        a = headA;
        b = headB;

        if (lenA > lenB) {
            int diff = lenA - lenB;

            while (diff-- > 0) {
                a = a.next;
            }
        } else {
            int diff = lenB - lenA;

            while (diff-- > 0) {
                b = b.next;
            }
        }

        // Now both pointers are at the same distance from the end
        while (a != null && b != null) {
            if (a == b) {
                return a;
            }

            a = a.next;
            b = b.next;
        }

        return null;
    }
}