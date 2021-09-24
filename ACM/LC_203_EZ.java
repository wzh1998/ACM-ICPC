// Virtual head solution
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        ListNode virtualHead = new ListNode(-1, head);
        ListNode currentNode = head;
        ListNode prevNode = virtualHead;
        
        while(currentNode != null) {
            if(currentNode.val == val) 
                prevNode.next = currentNode.next;
            
            else 
                prevNode = currentNode;
            
            currentNode = currentNode.next;
            
        }
        
        return virtualHead.next;
    }
}

class Solution {
    public ListNode removeElements(ListNode head, int val) {
        ListNode currentNode = head;
        ListNode prevNode = new ListNode(-1);
        ListNode result = null;
        
        prevNode.next = head;
        
        boolean foundHead = false;
        
        while(currentNode != null) {
            if(currentNode.val == val) {
                prevNode.next = currentNode.next;
                currentNode = currentNode.next;
            }
            else {
                if(!foundHead){
                    result = currentNode;
                    foundHead = true;
                }
                prevNode = currentNode;
                currentNode = currentNode.next;
            }
        }
        
        return result;
    }
}