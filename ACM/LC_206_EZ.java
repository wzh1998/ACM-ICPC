/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-08-31 20:49:50
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-12-30 23:53:22
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

// 20.12 Update a more understandable solution
public ListNode reverseList(ListNode head) {
        
        ListNode currentNode = head;
        ListNode nextNode = null;
        ListNode prevNode = null;
        
        while(currentNode != null) {
            nextNode = currentNode.next;
            currentNode.next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
        }
        
        return prevNode;
}

// Iterative
class Solution {
    	public ListNode reverseList(ListNode head) {
        ListNode prevHead = null;
        while(head != null) {
        	ListNode recordNext = head.next;
        	head.next = prevHead; // Important, reverse the link here
        	prevHead = head;
        	head = recordNext;
        }
        return prevHead;
    }
}

// Recursive
class Solution {
    ListNode newHead = new ListNode(0);
	ListNode current = newHead;
	
	public ListNode reverseList(ListNode head) {
		if(head == null) return head;
		if(head.next != null) 
			reverseList(head.next);
        
        current.next = head;
        current = current.next;
        head.next = null;
        
        return newHead.next;
    }
}