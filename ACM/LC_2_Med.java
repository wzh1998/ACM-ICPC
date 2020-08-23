/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-08-23 17:30:04
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-08-23 17:30:09
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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int C = 0;
        int currentValue;
        ListNode head = new ListNode(0);
        ListNode tail = head;
        
        while(l1 != null || l2 != null || C > 0) {
        	currentValue = (l1 == null ? 0 : l1.val) + (l2 == null ? 0 : l2.val) + C;
        	l1 = (l1 == null) ? l1 : l1.next;
        	l2 = (l2 == null) ? l2 : l2.next;
        	
        	tail.next = new ListNode(currentValue % 10);
        	tail = tail.next;
        	
        	C = currentValue / 10;
        } 
        return head.next;
    }
}