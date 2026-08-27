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
    public ListNode partition(ListNode head, int x) {
        ListNode lesserHead = new ListNode(-1);
        ListNode lesserTail = lesserHead;

        ListNode greaterHead = new ListNode(-1);
        ListNode greaterTail = greaterHead;

        ListNode temp = head;

        while(temp != null){
            if(temp.val < x){
            // seperate this node and append to lesser wali LL
            // also before doing this, make sure temp points to the head of remainning LL
            ListNode nodeToInsert = temp;
            temp = temp.next;
            nodeToInsert.next = null;
            // insert at tail -> less wali LL me
            lesserTail.next = nodeToInsert;
            lesserTail = nodeToInsert;
            }
            else{
                ListNode nodeToInsert = temp;
                temp = temp.next;
                nodeToInsert.next = null;
                // insert at tail -> greater wali LL
                greaterTail.next = nodeToInsert;
                greaterTail = nodeToInsert;
            }
        }

        // yahan pr, humari sub list ready hai
        // join them
        // also remove dummy nodes
        lesserTail.next = greaterHead.next;
        greaterHead.next = null;
        // remove starting wali dummy node
        lesserHead = lesserHead.next;

        // return answer
        return lesserHead;
    }
}