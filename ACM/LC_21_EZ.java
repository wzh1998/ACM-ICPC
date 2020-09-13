/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-09-13 16:31:59
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-09-13 16:32:03
*/

public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
		ListNode head = new ListNode(0);
		ListNode current = head;
		
        while(l1 != null && l2 != null) {
        	if(l1.val <= l2.val) {
        		current.next = new ListNode(l1.val);
        		current = current.next;
        		l1 = l1.next;
        		
        	}
        	else {
        		current.next = new ListNode(l2.val);
        		current = current.next;
        		l2 = l2.next;
        	}
        }
        
        l1 = (l1 == null) ? l2 : l1;
        while(l1 != null) {
        	current.next = new ListNode(l1.val);
        	current = current.next;
        	l1 = l1.next;
        }
        
        return head.next;
    }