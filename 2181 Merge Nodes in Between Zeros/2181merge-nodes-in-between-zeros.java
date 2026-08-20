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
    public ListNode mergeNodes(ListNode head) {
        ListNode read = head.next;
        ListNode write = head;
        while(read != null){
            int sum = 0;
            // calculate sum ki value till you get a 0 value wali node
            while(read.val != 0){
                sum = sum + read.val;
                read = read.next;
            }
            // insert sum ki value ko 0 wali position
            write.val = sum;
            // delete faltu nodes
            write.next = read.next;
            // read and write ko move kardo 1 step
            read = read.next;
            write = write.next;
        }
        return head;
    }
}