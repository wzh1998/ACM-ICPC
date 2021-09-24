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
    public ListNode swapPairs(ListNode head) {
        if(head == null || head.next == null)
            return head;
        
        ListNode prevNode, node1, node2, nextNode;
        ListNode virtualHead = new ListNode(0, head);
            
        prevNode = virtualHead;
        node1 = head;
        node2 = head.next;
        while(node2 != null) {
            // step 1: backup
            nextNode = node2.next;
            // step 2: swap location
            node2.next = node1;
            node1.next = nextNode;
            prevNode.next = node2;
            // step 3: move to the next location
            prevNode = node1;
            node1 = nextNode;
            node2 = (node1 == null ? null : node1.next);
        }
        
        return virtualHead.next;
    }
}