/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-09-13 15:33:33
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-09-13 16:14:26
*/

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
    public ListNode oddEvenList(ListNode head) {
		if(head == null || head.next == null) return head;
		
		ListNode start = head;
        ListNode evenHead = head.next; // mandatory
        ListNode oddTail = head; // mandatory
        ListNode nextNode; // mandatory
        
        for(boolean isOdd = true; true; isOdd = !isOdd) {
        	if(head.next.next == null) {
        		if(!isOdd) head.next = null;
        		break;
        	}
        	nextNode = head.next;
        	head.next = nextNode.next;
        	head = nextNode;
        	
        	if(isOdd)
        		oddTail = head.next;
        }
        oddTail.next = evenHead;
        
        return start;
        
    }
}