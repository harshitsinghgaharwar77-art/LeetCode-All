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
    public ListNode mergeKLists(ListNode[] lists) {

        // Min-heap based on node value
        PriorityQueue<ListNode> pq =
            new PriorityQueue<>((a, b) -> a.val - b.val);

        int k = lists.length;

        if (k == 0) {
            return null;
        }

        // Push first node of every list
        for (int i = 0; i < k; i++) {
            if (lists[i] != null) {
                pq.offer(lists[i]);
            }
        }

        ListNode head = null;
        ListNode tail = null;

        while (!pq.isEmpty()) {

            ListNode temp = pq.poll();

            // Push the next node from the same list
            if (temp.next != null) {
                pq.offer(temp.next);
            }

            // First node
            if (head == null) {
                head = temp;
                tail = temp;
            } else {
                tail.next = temp;
                tail = temp;
            }
        }

        // End the merged list
        if (tail != null) {
            tail.next = null;
        }

        return head;
    }
}