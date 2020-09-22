/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-09-22 20:49:34
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-09-22 20:49:40
*/
class MinStack {

    /** initialize your data structure here. */
    Stack<Integer> stack;
    int minimum;
    public MinStack() {
    	stack = new Stack<> ();
    	minimum = Integer.MAX_VALUE;
    }
    
    public void push(int x) {
        
    	if(x <= minimum) {
    		stack.push(minimum);
    		minimum = x;
    	}
    	stack.push(x);
    }
    
    public void pop() {
        if(stack.pop() == minimum) minimum = stack.pop();
    }
    
    public int top() {
        return stack.peek();
    }
    
    public int getMin() {
        return minimum;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */