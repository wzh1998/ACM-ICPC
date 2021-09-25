/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;
        
        // detect the cycle
        while(fast != null) {
            fast = (fast.next == null) ? null : fast.next.next;
            slow = slow.next;
            if(fast == null) return null;
            else if(fast == slow) break;
        }
        // find the entrance
        ListNode index0 = head;
        ListNode index1 = fast;
        
        while(index0 != index1) {
            index0 = index0.next;
            index1 = index1.next;
        }
        
        return index0;
    }
}