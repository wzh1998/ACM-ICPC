/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-09-01 21:12:56
* @Last Modified by:   zihaowang
* @Last Modified time: 2021-09-25 00:51:33
*/
// fast and slow pointer solution 2021
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode slow, fast;
        ListNode virtualHead = new ListNode(0, head);
        
        fast = head;
        
        for(int i = 0; i < n; i++) 
            fast = fast.next;
        
        slow = virtualHead;
        while(fast != null) {
            fast = fast.next;
            slow = slow.next;
        }
        slow.next = slow.next.next;
        
        return virtualHead.next;
    }
}


// previous naive solution
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
		List<ListNode> al = new ArrayList<> ();
		ListNode prevNode, targetNode;
		while(head != null) {
			al.add(head);
			head = head.next;
		}
		
		targetNode = al.get(al.size() - n);
		prevNode = (n == al.size()) ? targetNode : al.get(al.size() - n - 1); // add if statement
		
		prevNode.next = targetNode.next;
		targetNode.next = null;
		al.remove(al.size() - n);
		
		return (al.size() == 0 ? null : al.get(0));
    }
}