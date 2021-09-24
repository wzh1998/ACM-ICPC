class ListNode {
    int val;
    ListNode next;
    
    ListNode(int val) {
        this.val = val;
    }
    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class MyLinkedList {
    ListNode head;
    ListNode tail;
    int len;
    /** Initialize your data structure here. */
    public MyLinkedList() {
        head = new ListNode(0);
        tail = new ListNode(0);
        len = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    public int get(int index) {
        if(index < 0 || index >= len)
            return -1;
        ListNode currentNode = head;
        
        for(int i = 0; i <= index; i++) 
            currentNode = currentNode.next;
        
        return currentNode.val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    public void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    /** Append a node of value val to the last element of the linked list. */
    public void addAtTail(int val) {
        
        addAtIndex(len, val);
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    public void addAtIndex(int index, int val) {
        if(index < 0 || index > len)
            return;
        
        ListNode currentNode = head;
        for(int i = 0; i < index; i++) 
            currentNode = currentNode.next;
        
        ListNode newNode = new ListNode(val, currentNode.next);
        currentNode.next = newNode;
        
        len++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    public void deleteAtIndex(int index) {
        if(index < 0 || index >= len)
            return;
        
        ListNode currentNode = head;
        for(int i = 0; i < index; i++) 
            currentNode = currentNode.next;
        if(index == len - 1)
            tail = currentNode;
            
        currentNode.next = currentNode.next.next;
        len--;
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */