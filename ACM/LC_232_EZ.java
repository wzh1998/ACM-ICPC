class MyQueue {
    Stack<Integer> stackIn;
    Stack<Integer> stackOut;
    public MyQueue() {
        stackIn = new Stack<> ();
        stackOut = new Stack<> ();
    }
    
    public void push(int x) {
        stackIn.push(x);
    }
    
    public int pop() {
        if(!stackOut.isEmpty()) 
            return stackOut.pop();
        // export data to stack out
        while(!stackIn.isEmpty()) 
            stackOut.push(stackIn.pop());
        // push the result
        return stackOut.pop();
    }
    
    public int peek() {
        if(!stackOut.isEmpty()) 
            return stackOut.peek();
        // export data to stack out
        while(!stackIn.isEmpty()) 
            stackOut.push(stackIn.pop());
        // push the result
        return stackOut.peek();
    }
    
    public boolean empty() {
        return (stackIn.isEmpty() && stackOut.isEmpty());
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */