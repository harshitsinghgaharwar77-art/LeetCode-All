/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        // base case
        if(head == null) return null;
        // step-1: clone nodes add
        Node temp = head;
        while(temp != null){
            Node cloneNode = new Node(temp.val);
            cloneNode.next = temp.next;
            temp.next = cloneNode;
            temp = cloneNode.next;
        }
        // step-2: copy random pointers
        temp = head;
        while(temp != null){
            Node oldNode = temp;
            Node newNode = temp.next;
            // observation -> newNode ka random = oldNode ka random ka next
            if(oldNode.random != null){
                newNode.random = oldNode.random.next;
            }
            // temp ko move krna padega
            temp = newNode.next;
        }
        // step-3: detach the LIST
        temp = head;
        Node ansListHead = head.next;
        while(temp != null){
            Node oldNode = temp;
            Node cloneNode = temp.next;
            // detach ka logic
            oldNode.next = cloneNode.next;
            if(cloneNode.next != null) {cloneNode.next = cloneNode.next.next;
            }
            // temp ko move karo
            temp = temp.next;
        }
        return ansListHead;
    }
}