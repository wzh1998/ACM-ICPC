class MyStack {
    Queue<Integer> queue;
    
    public MyStack() {
        queue = new LinkedList<> ();
    }
    
    public void push(int x) {
        queue.add(x);
    }
    
    public int pop() {
        for(int i = 0; i < queue.size() - 1; i++) 
            queue.add(queue.poll());
        
        return queue.poll();
    }
    
    public int top() {
        int result = pop();
        queue.add(result);
        
        return result;
    }
    
    public boolean empty() {
        return queue.isEmpty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */