/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-09-01 21:12:56
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-09-01 21:28:31
*/
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